######## 1.
## Data
Accident <- matrix(c(1601, 510, 162527, 412368), nrow = 2)
dimnames(Accident) <- list(SB = c("No","Yes"), Death = c("Yes","No"))

######## 1-(a)
rslt1a = prop.test(Accident)
rslt1a$estimate   ## ratio estimate
rslt1a$p.value    ## p value

######## 1-(b)
library(epitools)
rslt1b = riskratio(Accident,rev="both",method="wald")
rslt1b$measure[2,1]    ## ralative risk
rslt1b$p.value[2,3]    ## p value

######## 1-(c)
rslt1c = oddsratio(Accident, rev="both", method="wald")
rslt1c$measure[2,1]    ## odds ratio
rslt1c$p.value[2,3]    ## p value

######## 2.
## Data
Data_partial = c(6,2,4,8,4,1,3,5,5,3,3,6)
Migraine_partial = array(Data_partial,dim=c(2,2,3), 
                      dimnames=list(Treatment=c("Med","Pla"), 
                                    Response=c("S","F"),
                                    Hospital=c("Hos1","Hos2","Hos3")))

Migraine_marginal = matrix(c(15,6,10,19), nrow=2)
dimnames(Migraine_marginal) = list(Treatment=c("Med","Pla"), Response=c("S","F"))

######## 2-(a)
rslt2a = oddsratio(Migraine_marginal, rev="both", method="wald")
rslt2a$measure[2,1]    ## odds ratio
rslt2a$p.value[2,3]    ## p value

######## 2-(b)
library(samplesizeCMH)
rslt2b = mantelhaen.test(Migraine_partial,correct=F)
rslt2b$p.value   ## p value 

######## 2-(c)
library(DescTools)
rslt2c = BreslowDayTest(x = Migraine_partial)
rslt2c$p.value    ## p value

