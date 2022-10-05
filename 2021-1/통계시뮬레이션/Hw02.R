# 01-1 X는 전체 실패 횟수입니다.
max <- 10000
p <- 0.1
r <- seq(1,100,1)

mean.nbinom <- function(r){
  x.cdf <- pnbinom(0:max,r,p)
  ran.unif <- runif(1000)
  inv.trns <- rep(NA,length(ran.unif))
  for(i in 1:length(ran.unif)){
    inv.trns[i] <- min(which(ran.unif[i] < x.cdf))-1
  }
  return(mean(inv.trns))
}

mean.trns <- rep(NA,length(r))

for(i in r){
  mean.trns[i] <- mean.nbinom(i)
}

plot(x=r,y=mean.trns,type='l')

# 01-2 X는 전체 실패 횟수이며, for문으로 돌립니다.
max <- 10000
p <- 0.1
r <- seq(1,100,1)

mean.trns <- rep(NA,length(r))

for(i in r){
  x.cdf <- pnbinom(0:max,i,p)
  ran.unif <- runif(1000)
  inv.trns <- rep(NA,length(ran.unif))
  for(j in 1:length(ran.unif)){
    inv.trns[j] <- min(which(ran.unif[j] < x.cdf))-1
  }
  mean.trns[i] <- mean(inv.trns)
}

plot(x=r,y=mean.trns,type='l')

# 02-1 X는 전체 시행 횟수입니다.
max <- 10000
p <- 0.1
r <- seq(1,100,1)

mean.nbinom <- function(r){
  x.cdf <- pnbinom(0:max,r,p)
  ran.unif <- runif(1000)
  inv.trns <- rep(NA,length(ran.unif))
  for(i in 1:length(ran.unif)){
    inv.trns[i] <- min(which(ran.unif[i] < x.cdf))-1+r
  }
  return(mean(inv.trns))
}

mean.trns <- rep(NA,length(r))

for(i in r){
  mean.trns[i] <- mean.nbinom(i)
}

lines(x=r,y=mean.trns,type='l')

# 02-2 X는 전체 시행 횟수이며, for문으로 돌립니다.
max <- 10000
p <- 0.1
r <- seq(1,100,1)

mean.trns <- rep(NA,length(r))

for(i in r){
  x.cdf <- pnbinom(0:max,i,p)
  ran.unif <- runif(1000)
  inv.trns <- rep(NA,length(ran.unif))
  for(j in 1:length(ran.unif)){
    inv.trns[j] <- min(which(ran.unif[j] < x.cdf))-1+i
  }
  mean.trns[i] <- mean(inv.trns)
}

lines(x=r,y=mean.trns,type='l')

# sys.time을 이용하여 걸리는 시간 측정
# 난수를 100000개 생성, r의 경우의 수를 1000까지