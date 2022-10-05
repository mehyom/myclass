#################### 01
## Data
Accident <- matrix(c(54,25,10325,51790), nrow = 2)
dimnames(Accident) <- list(SB = c("No","Yes"), Death = c("Yes","No"))
## 1-(a)
prop.table(Accident, margin=1) ## ratio
r1a = prop.test(Accident)
r1a$p.value    ## p value
## 1-(b)
library(epitools)
r1b = riskratio(Accident,rev="both",method="wald")
r1b$measure[2,1]    ## ralative risk
r1b$p.value[2,3]    ## p value
## 01-(c)
r1c = oddsratio(Accident, rev="both", method="wald")
r1c$measure[2,1]    ## odds ratio
r1c$p.value[2,3]    ## p value

#################### 02
## Data
Attack <- matrix(c(170,90,173,347), nrow = 2)
dimnames(Attack) <- list(Smoke = c("Y","N"), AMI = c("Y","N"))
## 02-(b)
r2b = oddsratio(Accident, rev="both", method="wald")
r2b$measure[2,1]    ## odds ratio
r2b$p.value[2,3]    ## p value

#################### 05
##Data
Metro = c(10,22,5,11,6,18,10,17,6,16,9,15,6,17,9,17,
                  9,12,14,25,13,12,11,12,10,14,15,10,10,15,17,16)
Metro_partial = array(Metro,dim=c(2,2,8), 
                         dimnames=list(Sex=c("M","F"), 
                                       Prefer=c("Y","N"),
                                       Line=c("1","2","3","4",
                                              "5","6","7","8")))
## 05-(b)
library(samplesizeCMH)
r5b = mantelhaen.test(Metro_partial,correct=F)
r5b$p.value   ## p value

#################### 07
Data <- data.frame(Year=c(1970:1983),
                   Crush=c(11,8,8,4,6,5,2,4,1,7,3,5,1,2),
                   Distance=c(281,276,284,269,281,241,265,
                                 264,267,263,267,260,231,249))
## 07-(a)
model_poi = glm(Crush~Distance,family=poisson,data=Data)
predict(model_poi,data=Data,type="response")[1:6]
library(lmtest)
waldtest(model_poi) # Walds statistics
lrtest(model_poi) # LR statistics
## 07-(b)
discretize <- function(x){
  cat1 = (x<235)
  cat2 = (x>=235&x<245)
  cat3 = (x>=245&x<255)
  cat4 = (x>=255&x<265)
  cat5 = (x>=265&x<275)
  cat6 = (x>=275)
  cat_vec = cat1*231+cat2*241+cat3*249+cat4*262.33+cat5*267+cat6*280.5
  obs_cat = factor(cat1*1+cat2*2+cat3*3+cat4*4+cat5*5+cat6*6)
  return(list(cat_vec,obs_cat))
}
cat_Data <- Data
disc_results <- discretize(cat_Data$Distance)
cat_Data$Distance <- disc_results[[1]]
cat_Data
## 07-(c)
cmodel_poi <- glm(Crush~Distance,family=poisson,data=cat_Data)
myTable <- aggregate(cat_Data$Crush,by=list(W=(cat_Data$Distance)),FUN=sum)
myTable$freq <- table(cat_Data$Distance)
names(myTable)[2] <- "total_Crush"
names(myTable)[1] <- "Distance"
myTable$muhat <- exp(predict(cmodel_poi,newdata=myTable))*myTable$freq
# Goodness-of-fit statistics
Xsq = sum((myTable$total_Crush-myTable$muhat)^2/myTable$muhat)
Xsq
Gsq = 2*sum(myTable$total_Crush*log(myTable$total_Crush/myTable$muhat))
Gsq
# Pearson residuals
myTable$pearson = ((myTable$total_Crush)-myTable$muhat)/sqrt(myTable$muhat)
# Adjusted residuals
library(boot)
probit_diag = glm.diag(cmodel_poi)
poi_h = aggregate(probit_diag$h,by=list((disc_results[[2]])), FUN=sum)[,2]
myTable$adjr = myTable$pearson/sqrt(1-poi_h)
myTable
