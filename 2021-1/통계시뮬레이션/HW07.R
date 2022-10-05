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
