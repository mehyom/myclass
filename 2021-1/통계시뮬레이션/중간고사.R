## EXAM 01
## 20190917 통계학과 신효민

### 01 ###
# (a)
s.size <- 1000
alpha <- 2
beta <- 3
x.exp <- matrix(rexp(s.size*(alpha+beta)),s.size,(alpha+beta))
a.gamma <- apply(x.exp[,1:alpha],1,sum)
b.gamma <- apply(x.exp[,(alpha+1):(alpha+beta)],1,sum)
x.beta <- sort(a.gamma/(a.gamma+b.gamma))

# (b)
prob <- (rank(x.beta)-0.5)/length(x.beta)
plot(x=x.beta,y=qbeta(prob,alpha,beta),type='l')
abline(a=0,b=1,lty=3)

# (c)
r.size <- 999
a <- seq(0.01,0.99,0.01)
theta0 <- pbeta(a,alpha,beta)
x.mon <- matrix(NA,r.size,length(a))
for(i in 1:length(a)){
  x.mon[,i] <- runif(r.size,0,a[i])
}
gx <- (factorial(alpha+beta-1)/(factorial(alpha-1)*factorial(beta-1))
       *x.mon^(alpha-1)*(1-x.mon)^(beta-1))
gx.bar <- apply(gx,2,mean)
theta.hat <- a*gx.bar
plot(x=theta.hat,y=theta0,type='l')
abline(a=0,b=1,lty=3)

# (d)
bern.p <- mean(x.beta)
ran.bern <- matrix(sample(c(1,0),50000,replac=T,
                          prob=c(bern.p,(1-bern.p))),1000,50)

# (e)
z.value <- qnorm(0.975)
binom.p <- apply(ran.bern,1,mean)
binom.95ci <- matrix(NA,1000,2)
binom.95ci[,1] <- binom.p-z.value*sqrt(binom.p*(1-binom.p)/50)
binom.95ci[,2] <- binom.p+z.value*sqrt(binom.p*(1-binom.p)/50)
binom.bool <- array(NA,1000)
binom.bool <- ifelse(binom.95ci[,1]<bern.p&bern.p<binom.95ci[,2],1,0)
ci.percent <- mean(binom.bool)*100

# (f)
ran.geom <- array(NA,1000)
for(i in 1:nrow(ran.bern)){
  trial <- 1
  while(TRUE){
    if(ran.bern[i,trial]==1){
      ran.geom[i] <- trial-1
      break()
    }
    else{
      trial=trial+1
    }
  }
}
  
# (g)
geom.p <- 1/(mean(ran.geom)+1)
range <- min(ran.geom):max(ran.geom)
hist(ran.geom,breaks=15,freq=FALSE)
lines(x=range,y=dgeom(range,geom.p))

### 02 ###
Z <- matrix(rnorm(1000*3),1000,3)
V <- sort(apply(Z^2,1,sum))
the.p <- pnorm(V) #the.p <- pnorm(V,Z의 표본평균, Z의 표본표준편차)
plot(x=prob,y=the.p,type='l')
abline(a=0,b=1,lty=3)
