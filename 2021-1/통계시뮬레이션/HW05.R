s.size <- 10000

seq.x <- seq(-4,4,0.01)
ran.norm <- rnorm(s.size,0,1)
est.Phi <- var.est.Phi <- rep(NA,length(seq.x))
for(i in 1:length(seq.x)){
  est.Phi[i] <- mean(ran.norm<=seq.x[i])
  var.est.Phi[i] <- var(ran.norm<=seq.x[i])/s.size
}
cil.est.Phi <- est.Phi-1.96*sqrt(var.est.Phi)
ciu.est.Phi <- est.Phi+1.96*sqrt(var.est.Phi)

plot(x=seq.x,y=est.Phi,type='s')
lines(x=seq.x,y=pnorm(seq.x,0,1),col='red')
lines(x=seq.x,y=ciu.est.Phi,col='blue')
lines(x=seq.x,y=cil.est.Phi,col='blue')

seq.y <- seq(0.01,10,0.01)
df <- 2
ran.chq <- rchisq(s.size,df)
est.chq <- var.est.chq <- rep(NA,length(seq.y))
for(i in 1:length(seq.y)){
  est.chq[i] <- mean(ran.chq<=seq.y[i])
  var.est.chq[i] <- var(ran.chq<=seq.y[i])/s.size
}
cil.est.chq <- est.chq-1.96*sqrt(var.est.chq)
ciu.est.chq <- est.chq+1.96*sqrt(var.est.chq)

plot(x=seq.y,y=est.chq,type='s')
lines(x=seq.y,y=pchisq(seq.y,df),col='red')
lines(x=seq.y,y=ciu.est.chq,col='blue')
lines(x=seq.y,y=cil.est.chq,col='blue')

seq.z <- seq(0,1,0.001)
alpha <- 3; beta <- 3
ran.beta <- rbeta(s.size,alpha,beta)
est.bta <- var.est.bta <- rep(NA,length(seq.z))
for(i in 1:length(seq.z)){
  est.bta[i] <- mean(ran.beta<=seq.z[i])
  var.est.bta[i] <- var(ran.beta<=seq.z[i])/s.size
}
cil.est.bta <- est.bta-1.96*sqrt(var.est.bta)
ciu.est.bta <- est.bta+1.96*sqrt(var.est.bta)

plot(x=seq.z,y=est.bta,type='s')
lines(x=seq.z,y=pbeta(seq.z,alpha,beta),col='red')
lines(x=seq.z,y=ciu.est.bta,col='blue')
lines(x=seq.z,y=cil.est.bta,col='blue')
