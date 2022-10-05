## Odds ratio function
cal_or = function(table){
  return (table[1,1]*table[2,2]/table[1,2]/table[2,1])
}

######## 1.
## Table 1.
Accident <- matrix(c(54, 25, 10325, 51790), nrow = 2)
dimnames(Accident) <- list(SB = c("No","Yes"), Death = c("Yes","No"))

## 1-(a)
rslt1a = prop.test(Accident)
rslt1a$estimate   ## ratio estimate
rslt1a$p.value    ## p value

## 1-(b)
library(epitools)
rslt1b = riskratio(Accident,rev="both",method="wald")
rslt1b$measure[2,1]    ## ralative risk
rslt1b$measure[2,2:3]  ## confidence interval
rslt1b$p.value[2,3]    ## p value

## 1-(c)
rslt1c = oddsratio(Accident, rev="both", method="wald")
rslt1c$measure[2,1]    ## odds ratio
rslt1c$measure[2,2:3]  ## confidence interval
rslt1c$p.value[2,3]    ## p value


######## 2.
## Table 2.
MI <- matrix(c(170, 90, 173, 347), nrow = 2)
dimnames(MI) <- list(Smoking = c("Yes","No"), MI = c("Yes","No"))

## 2-(b)
rslt2a = oddsratio(MI, rev="both", method="wald")
rslt2a$measure[2,1]    ## odds ratio
rslt2a$measure[2,2:3]  ## confidence interval
rslt2a$p.value[2,3]    ## p value


######## 4.
## 4-(a)
Data_thyroid = c(200,80,200,120,90,240,10,60)
Table_thyroid_partial = array(Data_thyroid,dim=c(2,2,2), 
                              dimnames=list(Hospital=c("A","B"), 
                                            Death=c("No","Yes"),
                                            Stage=c("Late","Early")))

## 4-(b)
or1 = cal_or(Table_thyroid_partial[,,1])
or2 = cal_or(Table_thyroid_partial[,,2])

## 4-(c)
mor = ((200+90)*(120+60))/((80+240)*(200+10))


######## 5.
## Table 3.
Data_subway = c(10,22,5,11, 6,18,10,17, 6,16,9,15, 6,17,9,17, 9,12,14,25, 
                13,12,11,12, 10,14,15,10, 10,15,17,6)
Table_subway_partial = array(Data_subway,dim=c(2,2,8), 
                       dimnames=list(Gender=c("Male","Female"), 
                                     Preference=c("Yes","No"),
                                     Line=c("1","2","3","4",
                                            "5","6", "7","8")))

## 5-(a)
for (i in 1:8){
  print(cal_or(Table_subway_partial[,,i]))
}

## 5-(b)
library(samplesizeCMH)
rslt4b = mantelhaen.test(Table_subway_partial,correct=F)
rslt4b
rslt4b$p.value   ## p-value of the CMH test
rslt4b$estimate  ## common odds ratio
rslt4b$conf.int  ## conf.int of the common odds ratio


######## 7.
## Table 4.
collision = c(11,8,8,4,6,5,2,4,1,7,3,5,1,2)
distance = c(281,276,284,269,281,241,265,264,267,263,267,260,231,249)
Train = data.frame(collision, distance)

## 7-(a)
rslt6a = glm(collision~distance, family = poisson, data = Train)
summary(rslt6a)
summary(rslt6a)$coeff

## Walds statistics
library(lmtest)
waldtest(rslt6a,test="Chisq")

## LR statistics
lrtest(rslt6a)

## 7-(b)
## discretization
discretize = function(x){
  cat1 = (x<235)
  cat2 = (x>=235 & x<245)
  cat3 = (x>=245 & x<255)
  cat4 = (x>=255 & x<265)
  cat5 = (x>=265 & x<275)
  cat6 = (x>=275)
  
  m1 = round(mean(x[cat1]),2)
  m2 = round(mean(x[cat2]),2)
  m3 = round(mean(x[cat3]),2)
  m4 = round(mean(x[cat4]),2)
  m5 = round(mean(x[cat5]),2)
  m6 = round(mean(x[cat6]),2)
  
  cat_vec = cat1*m1+cat2*m2+cat3*m3+
    cat4*m4+cat5*m5+cat6*m6
  obs_cat = factor(cat1*1+cat2*2+cat3*3+
                   cat4*4+cat5*5+cat6*6)
  
  return(list(cat_vec,obs_cat))
}

Train_cat = Train
disc_results = discretize(Train$distance)
Train_cat$distance = disc_results[[1]]

## 7-(c)
rslt6c = glm(collision~distance, family = poisson, data = Train_cat)

Train_table = aggregate(Train_cat$co, by=list(distance=(Train_cat$dist)), FUN=sum)
Train_table$freq = table(Train_cat$dist)
names(Train_table)[2]="tot_col"

## mu hat
Train_table$muhat = predict(rslt6c,newdata = Train_table,type="response")*
  Train_table$freq

## Goodness-of-fit statistics
Xsq = sum((Train_table$tot_col-Train_table$muhat)^2/Train_table$muhat)
Xsq
1-pchisq(Xsq, df=4)

Gsq = 2*sum(Train_table$tot_col*log(Train_table$tot_col/Train_table$muhat))
Gsq
1-pchisq(Gsq, df=4)

## Pearson residuals
Train_table$pearson = ((Train_table$tot_col)-Train_table$muhat)/
  sqrt(Train_table$muhat)

## Adjusted residuals
library(boot)
probit_diag = glm.diag(rslt6c)
probit_diag$h
poi_h = aggregate(probit_diag$h, by=list((disc_results[[2]])), FUN=sum)[,2]

Train_table$adjr = Train_table$pearson/sqrt(1-poi_h)




