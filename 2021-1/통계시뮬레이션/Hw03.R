### 01 ###
max <- 1000
r <- 10
prob <- ((1:max)-0.5)/max
dis.X <- function(n,x.cdf){
  x.mat <- matrix(nrow=max,ncol=n)
  for(i in 1:n){
    ran.unif <- runif(max)
    for(j in 1:max){
      x.mat[j,i] <- min(which(ran.unif[j]<x.cdf))-1
    }
  }
  S <- sort(apply(x.mat,1,sum))
  return(S)
}

p <- 0.2
geom.cdf <- pgeom(0:max,p)
S1 <- dis.X(r,geom.cdf)

# P-P plot
the.p.nb <- pnbinom(S1,r,p)
plot(x=prob,y=the.p.nb,type='l')
abline(a=0,b=1,lty=3)

# Q-Q plot
the.q.nb <- qnbinom(prob,r,p)
plot(x=S1,y=the.q.nb,type='l')
abline(a=0,b=1,lty=3)


### 02 ###
max <- 1000
prob <- ((1:max)-0.5)/max
exp2g <- function(n,lambda){
  x.mat <- matrix(nrow=max,ncol=n)
  for(i in 1:n){
    ran.unif <- runif(max)
    for(j in 1:max){
      x.mat[j,i] <- -log(1-ran.unif[j])/lambda
    }
  }
  S <- sort(apply(x.mat,1,sum))
  return(S)
}

lambda <- 3
S2 <- exp2g(r,lambda)

# P-P plot
the.p.g <- pgamma(S2,r,lambda)
plot(x=prob,y=the.p.g,type='l')
abline(a=0,b=1,lty=3)

# Q-Q plot
the.q.g <- qgamma(prob,r,lambda)
plot(x=S2,y=the.q.g,type='l')
abline(a=0,b=1,lty=3)

### 03 ###
# 감마분포의 누적확률분포의 역함수를 구하지 못해 rgamma를 이용했습니다
max <- 1000
prob <- ((1:max)-0.5)/max
lambda <- 3
rs <- seq(0.1,1,0.1)

for(i in seq(1,length(rs),1)){
  assign(paste0("G",i),rgamma(max,rs[i],lambda))
}

S3 <- sort(G1+G2+G3+G4+G5+G6+G7+G9+G10)

# P-P plot
the.p.gs <- pgamma(S3,sum(rs),lambda)
plot(x=prob,y=the.p.gs,type='l')
abline(a=0,b=1,lty=3)

# Q-Q plot
the.q.gs <- qgamma(prob,sum(rs),lambda)
plot(x=S3,y=the.q.gs,type='l')
abline(a=0,b=1,lty=3)
