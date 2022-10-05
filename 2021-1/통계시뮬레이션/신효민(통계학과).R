## 20190917 통계학과 신효민
## EXAM02

################################# 01 ###
### (a) ###
mu0 <- 0; sigma0 <- 1; size <- 10000
ran.norm <- sort((rnorm(size, 0.5, 1)-0.5)/1)
prob <- ((1:size)-0.5)/size
## Q-Q plot
plot(x=ran.norm,y=qnorm(prob,mean(ran.norm),sqrt(var(ran.norm))),type='l')
abline(a=0,b=1,lty=3,col='blue')
## P-P plot
plot(x=prob,y=pnorm(ran.norm,mean(ran.norm),sqrt(var(ran.norm))),type='l')
abline(a=0,b=1,lty=3,col='blue')

### (b) ###
x.index <- seq(0.01,3.99,0.01)
## Method 1
est.theta1 <- rep(NA,length(x.index))
for(i in 1:length(x.index)){
  ran.x <- runif(size,-x.index[i],x.index[i])
  ran.f <- 1/sqrt(2*pi*sigma0)*exp(-((ran.x-mu0)^2)/(2*sigma0))
  est.theta1[i] <- mean(ran.f)*(x.index[i]*2)
}
plot(x=x.index,y=est.theta1,type='l')
## Method 2
est.theta2 <- rep(NA,length(x.index))
ran.x <- rnorm(size,mu0,sqrt(sigma0))
for(i in 1:length(x.index)){
  ran.f <- ifelse(ran.norm<=x.index[i],1,0)
  est.theta2[i] <- mean(ran.f)
}
plot(x=x.index,y=est.theta2,type='l')

### (c) ###
var.est.theta <- est.theta2*(1-est.theta2)/size
ci95.theta <- matrix(rep(NA,length(x.index)*2),nrow=length(x.index))
ci95.theta[,1] <- est.theta2-qnorm(1-0.05/2)*sqrt(var.est.theta)
ci95.theta[,2] <- est.theta2+qnorm(1-0.05/2)*sqrt(var.est.theta)
lines(x=x.index,y=ci95.theta[,1],type='l',col='red')
lines(x=x.index,y=ci95.theta[,2],type='l',col='blue')

################################# 02 ###
size <- 10000
r.unif <- matrix(runif(size*2),size,2)
ran.f <- ifelse(apply(r.unif^2,1,sum)<1,1,0)
est.pi <- cumsum(ran.f*4)/(1:size)
plot(x=1:size,y=est.pi,type='l')
abline(h=pi)

################################# 03 ###
### (a) ###
raw.data <- c(2.4,3.9,5.5,7.4,8.1,9.1,9.2,9.3,9.5,9.5,9.7,10.9)
B <- 10000; raw.mean <- mean(raw.data); size <- length(raw.data)
boot.sample <- sample(raw.data,B,replace=T)
var.boot <- var(boot.sample); var.boot
mse.boot <- sum((boot.sample-raw.mean)^2)/B-1; mse.boot
bias.boot <- mean(boot.sample)-raw.mean; bias.boot
### (b) ###
alpha = 0.05
# the standard normal confidence interval
ci951.low <- mean(boot.sample)-qnorm(1-alpha/2)*sqrt(var.boot)
ci951.upp <- mean(boot.sample)+qnorm(1-alpha/2)*sqrt(var.boot)
c(ci951.low,ci951.upp)
# the bootstrap percentile confidence interval
ci952 <- quantile(boot.sample, probs=c(alpha/2,1-alpha/2))
ci952
### (c) ###
jack.mean <- rep(NA,size)
for(i in 1:size){
  jack.sample <- raw.data[-i]
  jack.mean[i] <- mean(jack.sample)
}
est.mu <- mean(jack.mean)
est.mu

################################# 04 ###
size <- 30; repl <- 1000; mu0 <- 10; sigma0.2 <- 10; alpha <- 0.05
sigma.2 <- seq(1,30,by=0.1)
### (a) ###
cv.x <- rep(NA,2); test.x <- rep(NA,repl)
emp.power <- rep(NA,length(sigma.2))
cv.x[1] <- qchisq(alpha/2,size-1)
cv.x[2] <- qchisq(1-alpha/2,size-1)
for(i in 1:length(sigma.2)){
  ran.x <- matrix(rnorm(repl*size,mu0,sqrt(sigma.2[i])),nrow=repl)
  for(j in 1:repl){
    test.x[j] <- ((size-1)*var(ran.x[j,]))/sigma0.2
  }
  emp.power[i] <- mean(ifelse(cv.x[1]<test.x&test.x<cv.x[2],0,1))
}
emp.power[which(sigma.2==sigma0.2)] # 제 1종 오류를 범할 확률
### (b) ###
plot(x=sigma.2,y=emp.power,type='l')
