############################# 1 ###
myDf <- data.frame(LI=rep(c(8,10,12,14,16,18,20,22,24,26,28,32,34,38),each=2),
                   cure=rep(c(1,0),times=14),
                   freq=c(1,5,1,6,1,7,1,4,2,4,2,2,2,1,1,1,1,2,2,2,5,1,4,1,3,1,8,1))
### (a) ###
myDf_logit = glm(cure~LI,family=binomial,data=myDf,weights=freq)
coef(myDf_logit)
### (b) ###
exp(coef(myDf_logit)[2])
exp(confint.default(myDf_logit))[2,]
### (c) ###
get_prob_int = function(logit_muhat,logit_sehat){
  lower_bound = logit_muhat-qnorm(0.975)*logit_sehat
  upper_bound = logit_muhat+qnorm(0.975)*logit_sehat
  lower_prob = exp(lower_bound)/(1+exp(lower_bound))
  upper_prob = exp(upper_bound)/(1+exp(upper_bound))
  return (c(lower_prob,upper_prob))
}
preds_logit = predict(myDf_logit,newdata=data.frame(LI=c(30)),type='link',se.fit=T)
get_prob_int(preds_logit$fit,preds_logit$se.fit)
### (d) ###
lr = deviance(glm(cure~1,family=binomial,data=myDf))-deviance(myDf_logit)
lr
1-pchisq(lr,df=1)

############################# 2 ###
Table2 = data.frame(drunk=rep(c("0","<1","1-2","3-5",">=6"),each=2),
                    deformed=rep(c(1,0),times=5))
Table2$n = c(40,420,47,174,20,53,38,45,50,25)
### (a) ###
T2_logit = glm(deformed~drunk,family=binomial,data=Table2) 
### (b) ###

### (c) ###
Table2 <- transform(Table2,
                    drunkNum=ifelse(drunk=="0",0.0,
                                  ifelse(drunk=="<1",0.5,
                                         ifelse(drunk=="1-2",1.5,
                                                ifelse(drunk=="3-5",4.0,
                                                       ifelse(drunk==">=6",7.0,-1
                                                ))))))

### (d) ###


############################# 4 ###
myTable = data.frame(Hospital=rep(c("A","B"),4),
                   Stage=rep(rep(c("Early","Late"),each=2),2),
                   Death=rep(c(0,1),each=4),
                   n=c(90,240,190,80,10,60,210,120),
                   total=rep(c(100,300,400,200),2))
### (a) ###
myTable$Hospital = factor(myTable$Hospital,levels=c("B","A"))
myTable$Stage = factor(myTable$Stage,levels=c("Late","Early"))
myT_logit = glm(Death~Hospital+Stage,family=binomial,data=myTable)
summary(myT_logit)
coef(myT_logit)
### (b) ###
myTable$yhat=0
myTable$yhat[1:4] = fitted(myT_logit)[1:4]*myTable$total[1:4]
myTable$yhat[5:8] = myTable$total[1:4]-myTable$yhat[1:4]
Gsq = 2*sum(myTable$n*log(myTable$n/myTable$yhat))
Gsq
1-pchisq(Gsq, df=1)
### (c) ###
wald=coef(summary(myT_logit))[2,3]^2
wald
1-pchisq(wald,df=1)

############################# 5 ###
Table4 = data.frame(Age=factor(rep(c("<45","45-49",">50"),each=3),
                               level=c("<45","45-49",">50")), 
                    SelfCheck=factor(rep(c("every month","often","none"),3),
                                     levels=c("every month","often","none"),ordered=T))
Table4$n = c(91,150,109,90,200,198,51,155,172)
### (a) ###
Table4 <- transform(Table4,
                    AgeNum=ifelse(Age=="<45",40,
                                  ifelse(Age=="45-49",47.5,
                                         ifelse(Age==">50",55,-1))))
T4_ord = polr(SelfCheck~AgeNum,weights=n,data=Table4,Hess=T)
summary(T4_ord)
coef(T4_ord)
### (b) ###
Walds = 4.802^2
1-pchisq(Walds, df=1)
