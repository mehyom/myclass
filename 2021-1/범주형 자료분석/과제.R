# 01-(1)
## 교통사고 데이터
data <- matrix(c(1601, 510, 162527, 412368), nrow = 2)
dimnames(data) <- list("안전벨트" = c("비착용","착용"), "사망여부" = c("사망","부상"))
## 안전벨트의 각 수준별 비율
prop.table(data, margin=1)
## 비율 차이가 유의한지 유의수준 0.05에서 검정 (결과를 해석하시오)
n_s = c(1601,510)
n_t = c(164128,412878)
prop.test(x=n_s, n=n_t, alternative="two.sided")

#01-(2)
## 상대위험 살펴보기
prop.out = prop.table(data, margin = 1)
prop.out[1,1]/prop.out[2,1]
## 상대위험 검정
#install.packages("epitools")
library(epitools)
#riskratio(MI,rev="columns")
riskratio(data,rev="columns")

# 01-(3)
## 오즈비
# odds of MI in Placebo
odds1 = prop.out[1,1]/prop.out[1,2]
odds1
# odds of MI in Aspirin
odds2 = prop.out[2,1]/prop.out[2,2]
odds2
# odds ratio
odds1/odds2
## 오즈비 검정
rslt3 = oddsratio(data, rev="both", method="wald")
rslt3$measure

rm(list=ls())
gc()

## Data 
Data = c(6,2,4,8,4,1,3,5,5,3,3,6)
partial_table = array(Data,dim=c(2,2,3), 
                      dimnames=list(치료방법=c("약","위약"), 
                                    반응=c("성공","실패"),
                                    병원=c("1","2","3")))
data <- matrix(c(15, 6, 10, 19), nrow = 2)
dimnames(data) <- list("치료방법" = c("약","위약"), "반응" = c("성공","실패"))
prop.table(data, margin=1)
prop.out = prop.table(data, margin = 1)
oddsratio(data, rev="columns")
## CMH Test
library(samplesizeCMH)
cmh_rslt = mantelhaen.test(partial_table,correct=F)
cmh_rslt
cmh_rslt$p.value   ## p-value of the CMH test
cmh_rslt$estimate  ## common odds ratio
cmh_rslt$conf.int  ## conf.int of the common odds ratio

library(DescTools)
bd_rslt = BreslowDayTest(x = partial_table)
bd_rslt
bd_rslt$p.value    ## p-value of the BD test
