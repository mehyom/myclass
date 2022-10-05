## Quiz04
################## 1-(a) ###
index.beta <- seq(0,0.99,by=0.01); n.size <- 1000; a0 <- 1.5; b0 <- 3
ran.beta <- rbeta(n.size,a0,b0)
est.theta <- rep(NA,length(index.beta))
for(i in 1:length(index.beta)){
  est.theta[i] <- mean(ran.beta<=index.beta[i])
}

plot(x=index.beta,y=est.theta,type='s')
lines(x=index.beta,y=pbeta(index.beta,a0,b0),col='red')

################## 1-(b) ###
alpha <- 0.05
var.est.theta <- rep(NA,length(index.beta))
for(i in 1:length(index.beta)){
  var.est.theta[i] <- var(ran.beta<=index.beta[i])/n.size
}

ci.est.theta <- matrix(NA,length(index.beta),2)
ci.est.theta[,1] <- est.theta-qnorm(1-alpha/2)*sqrt(var.est.theta)
ci.est.theta[,2] <- est.theta+qnorm(1-alpha/2)*sqrt(var.est.theta)

lines(x=index.beta,y=ci.est.theta[,1],col='blue')
lines(x=index.beta,y=ci.est.theta[,2],col='blue')
