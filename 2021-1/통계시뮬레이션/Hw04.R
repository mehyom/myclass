a <- seq(0.1,4.0,by=0.1)
theta0 <- pnorm(a,0,1)-0.5
s.size <- 10000
x <- matrix(nrow=s.size,ncol=length(a))
for(i in seq(1,length(a),1)){
  x[,i] <- runif(s.size,0,a[i])
}
gx <- 1/sqrt(2*pi)*exp(-x^2/2)
gx.bar <- apply(gx,2,mean)
theta.hat <- a*gx.bar
plot(x=a,y=theta.hat,type='l')
lines(x=a,y=theta0,lty=3)
