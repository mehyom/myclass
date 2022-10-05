############################## MonteCarlo pi 추정 ###
# 몬테칼로(Monte-Carlo) 방법을 이용하여 다음의 확률을 추정하시오.
# 그리고 추정결과로부터 π의 근사값이 구현됨을 보이시오.
# θ = Pr(√(x^2+y^2 ) < 1), 0<x<1, 0<y<1
s.size <- 10000
ran.unif <- matrix(runif(2*s.size),s.size,2)
ran.fctn <- ifelse(apply(ran.unif^2,1,sum)<1,1,0)
in.or.out <- ifelse(ran.fctn==1,'red','blue')
plot(ran.unif,type='p',pch=19,cex=0.25,col=in.or.out)
mean(ran.fctn)*4 # 3.1256
est.pi.cumsum <- cumsum(4*ran.fctn)/(1:s.size)
plot(x=1:s.size,y=est.pi.cumsum,type='l')
abline(h=pi,col=gray(0.7))

############################## MonteCarlo CI ###
seq.y <- seq(0.01,10,0.01); df <- 2; alpha=0.05
ran.chq <- rchisq(s.size,df)
est.chq <- var.est.chq <- rep(NA,length(seq.y))

for(i in 1:length(seq.y)){
  est.chq[i] <- mean(ran.chq<=seq.y[i])
  var.est.chq[i] <- var(ran.chq<=seq.y[i])/s.size
}
cil.est.chq <- est.chq-qnorm(1-alpha/2)*sqrt(var.est.chq)
ciu.est.chq <- est.chq+qnorm(1-alpha/2)*sqrt(var.est.chq)

plot(x=seq.y,y=est.chq,type='s')
lines(x=seq.y,y=pchisq(seq.y,df),col='red')
lines(x=seq.y,y=ciu.est.chq,col='blue')
lines(x=seq.y,y=cil.est.chq,col='blue')

############################## MonteCarlo ###
# Method.1 어디에든 적용 가능
index.x <- seq(0.01,1.00,0.01)
est1.theta.x <- var.est1.theta.x <- rep(NA,length(index.x))
for(i in 1:length(index.x)){
  ran.x <- runif(n.size,0,index.x[i])
  ran.f <- gamma(a0+b0)/(gamma(a0)*gamma(b0))*
    ran.x^(a0-1)*(1-ran.x)^(b0-1)
  est1.theta.x[i] <- mean(ran.f)*index.x[i]
  var.est1.theta.x[i] <- var(ran.f)/n.size
}
plot(x=index.x,y=est1.theta.x,type='l')

# Method.2 f(x)가 우리가 아는 pdf일 때만 적용 가능
# 표본의 분포로부터 나온 난수를 적분의 상한(x)와 비교하여 지시함수로 만듦
# 그 평균을 내어(표본의 평균으로) 모집단의 확률(cdf값)을 추정함
est2.theta.x <- var.est2.theta.x <- rep(NA,length(index.x))
ran.x <- rbeta(n.size,a0,b0)
for(i in 1:length(index.x)){
  ran.f <- ifelse(ran.x<=index.x[i],1,0)
  est2.theta.x[i] <- mean(ran.f)
  var.est2.theta.x[i] <- var(ran.f)/n.size
}
var.est3.theta.x <- est2.theta.x*(1-est2.theta.x)/n.size
# 0과 1로 이루어진 SIZE개의 자료를 이항분포라 생각할 수 있고
# est2.theta.x를 확률(p)의 추정량이라 생각해서 분산을 구함
plot(x=index.x,y=est2.theta.x,type='l')
lines(x=index.x, y=est1.theta.x,col='red')
lines(x=index.x,y=pbeta(index.x,a0,b0),col='blue')

############################## MonteCarlo Variance ###
size <- 20; repl <- 1000; alpha <- 0.01; mu0 <- 10; sigma0 <- 3
ran.norm <- matrix(rnorm(size*repl,mu0,sigma0),nrow=repl)
est.theta <- apply(ran.norm,1,var)
m.theta <- mean(est.theta)# E[theta_hat]
c.m.theta <- cumsum(est.theta)/1:repl # 1~10000까지 평균을 구해서
plot(x=1:repl,y=c.m.theta,type='l')
abline(h=1.1284,col='red')
low.theta <- (size-1)*est.theta/qchisq(1-alpha/2,df=size-1)
upp.theta <- (size-1)*est.theta/qchisq(alpha/2,df=size-1)
yes.no <- ifelse((low.theta<=sigma0^2)&(sigma0^2<=upp.theta),1,0)
mean(yes.no)
mean(est.theta) # sigma0^2와 비교
b.theta <- mean(est.theta)-sigma0^2 # bias(s^2) m.theta-theta0
mse.theta <- sum((est.theta-sigma0^2)^2)/repl^2
v.theta <- sum((est.theta-mean(est.theta))^2)/repl^2 #var(est.theta)/repl
# sigma0^2의 추정량(/repl)의 분산의 추정량(/repl)
# mse.theta = v.theta + b.theta^2
# F=MSR/MSE < F=MSR/VAR 검정통계량이 커지면 귀무가설을 기각할 확률이 커짐
# 연구자에게 불리하게 연구해 결과를 얻어내야 신뢰도가 높기 때문에 MSE 사용
V <- sort((size-1)*est.theta/sigma0^2)
prob <- ((1:repl)-0.5)/repl
# Q-Q Plot
plot(x=V,y=qchisq(prob,df=size-1),type='l')
abline(a=0,b=1,lty=3)
# P-P Plot
plot(x=prob,y=pchisq(V,df=size-1),type='l')
abline(a=0,b=1,lty=3)

############################## oneside test ###
# theta0-> type-I error(alpha) / theta-> type-II error(beta)
theta <- seq(500,600,2); theta0 <- 500
size <- 30; sigma0 <- 100; repl <- 1000; alpha <- 0.05
cv.x <- qt(1-alpha,size-1)
test.x <- rep(NA,repl)
emp.power <- rep(NA,length(theta))
for(i in 1:length(theta)){
  ran.x <- matrix(rnorm(size*repl,theta[i],sigma0),nrow=repl)
  for(j in 1:repl){
    test.x[j] <- (mean(ran.x[j,])-theta[1])/(sd(ran.x[j,])/sqrt(size))
  }
  yes.no <- ifelse(test.x > cv.x, 1, 0)
  emp.power[i] <- mean(yes.no)
}
plot(x=theta,y=emp.power,type='l')
emp.power[1] # alpha

############################## twoside test ###
theta <- seq(400,600,2); theta0 <- 500
size <- 30; sigma0 <- 100; repl <- 1000; alpha <- 0.05
cv.x <- qt(1-alpha/2,size-1)
test.x <- rep(NA,repl)
emp.power <- rep(NA,length(theta)) # 검정역 함수의 결과
for(i in 1:length(theta)){
  ran.x <- matrix(rnorm(size*repl,theta[i],sigma0),nrow=repl)
  for(j in 1:repl){
    test.x[j] <- abs((mean(ran.x[j,])-theta0)/(sd(ran.x[j,])/sqrt(size)))
  }
  yes.no <- ifelse(test.x > cv.x, 1, 0)
  emp.power[i] <- mean(yes.no)
}
plot(x=theta,y=emp.power,type='l')
emp.power[which(theta==theta0)]
# 검정역이란 대립가설이 맞다는 가정 하에서 나옴
# 검정역 함수란 어떤 가설이 맞는지는 모르지만, 귀무가설을 기각할 확률
# Chisq인 경우 (cv.x의 값이 원점을 기준으로 대칭이 아님)
theta <- seq(0,30,0.1); theta0 <- 10
size <- 30; mu0 <- 500; repl <- 1000; alpha <- 0.05
cv.x <- rep(NA,2)
cv.x[1] <- qchisq(alpha/2,size-1)
cv.x[2] <- qchisq(1-alpha/2,size-1)
test.x <- rep(NA,repl)
emp.power <- rep(NA,length(theta))
for(i in 1:length(theta)){
  ran.x <- matrix(rnorm(repl*size,mu0,sqrt(theta[i])),nrow=repl)
  for(j in 1:repl){
    test.x[j] <- ((size-1)*var(ran.x[j,]))/theta0
  }
  yes.no <- ifelse(cv.x[1] < test.x & test.x < cv.x[2],0,1)
  emp.power[i] <- mean(yes.no)
}
plot(x=theta,y=emp.power,type='l')
emp.power[which(theta==theta0)] # empirical alpha

############################## bootstrap ###
theta0 <- 500; sigma0 <- 100; size <- 30; repl <- 1000
sample.x <- rnorm(size,theta0,sigma0)
est.theta <- mean(sample.x)
sample.b <- matrix(sample(sample.x,size=size*repl,replace=TRUE),nrow=repl)
boot.theta <- mean(apply(sample.b,1,mean))
library(bootstrap)
head(law82)
Boot <- 1000; size <- nrow(law82); est.rho <- rep(NA,Boot)
Boot.index <- matrix(sample(1:size,size*Boot,replace=T),nrow=size)
for(i in 1:Boot){
  Boot.data <- law82[Boot.index[,i],2:3]
  est.rho[i] <- cor(x=Boot.data[,1],y=Boot.data[,2])
}

c.95ci.low <- mean(est.rho)-qnorm(0.975)*sqrt(var(est.rho))
c.95ci.upp <- mean(est.rho)+qnorm(0.975)*sqrt(var(est.rho))
quantile(est.rho,probs=c(0.025,0.975))
var.rho <- var(est.rho)
par.rho <- cor(x=law$LSAT,y=law$GPA)
mse.rho <- sum((est.rho-par.rho)^2)/(Boot-1)
bias.rho <- mean(est.rho)-par.rho # 왼쪽으로 꼬리가 길기 때문에 음수

############################## Jackknife ###
est.rho.j <- rep(NA,size)
for(i in 1:size){
  jack.data <- law82[-i,2:3]
  est.rho.j[i] <- cor(x=jack.data[,1],y=jack.data[,2])
}
bias.rho.j <- (size-1)*(mean(est.rho.j)-par.rho)
var.rho.j <- (size-1)/size*sum((est.rho.j-mean(est.rho.j))^2)
# 하나라도 더 많이 이용한 경우(Bootstrap)의 변동성이 작다

############################## linear regression ###
plot(law82[,-1])
a <- lm(GPA~LSAT,data=law82)
# GPA=0.8989+0.0037*LSAT (linear regression)
abline(a=0.8989,b=0.0037)
size <- nrow(law82); repl <- 10000; est.beta <- matrix(NA,nrow=repl,ncol=2)
for(i in 1:repl){
  index <- sample(1:size,size,replace=T)
  law82.B <- law82[index,]
  est.beta[i,] <- lm(GPA~LSAT,data=law82.B)$coefficients # y~x
}
head(est.beta)
par(mfrow=c(2,1))
hist(est.beta[,1],breaks=50)
hist(est.beta[,2],breaks=50)
############################## standard normal bootstrap CI ###
truth <- lm(GPA~LSAT,data=law82)$coefficients
type1.ci95.low <- truth-qnorm(0.975)*sqrt(diag(var(est.beta)))
type1.ci95.upp <- truth+qnorm(0.975)*sqrt(diag(var(est.beta)))
# Coefficients ANOVA of summary(a)
class.ci95.low <- truth-qt(0.975,size-2)*c(0.2142,0.0003578)
class.ci95.upp <- truth+qt(0.975,size-2)*c(0.2142,0.0003578)
############################## bootstrap percentile CI ###
quantile(est.beta[,1],probs=c(0.025,0.975))
quantile(est.beta[,2],probs=c(0.025,0.975))
############################## t bootstrap CI X ###