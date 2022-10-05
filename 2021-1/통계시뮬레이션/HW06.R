size <- 20; repl <- 1000; mu0 <- 10; sigma0 <- 3
ran.norm <- matrix(rnorm(size*repl,mu0,sigma0),nrow=repl)
est.theta <- apply(ran.norm,1,var)
V <- sort((size-1)*est.theta/sigma0^2)

prob <- ((1:repl)-0.5)/repl
# Q-Q Plot
plot(x=V,y=qchisq(prob,df=size-1),type='l')
abline(a=0,b=1,lty=3)
# P-P Plot
plot(x=prob,y=pchisq(V,df=size-1),type='l')
abline(a=0,b=1,lty=3)
