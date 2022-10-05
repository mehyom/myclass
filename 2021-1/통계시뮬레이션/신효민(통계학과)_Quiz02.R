## 01
max <- 10000
n <- 5
Z.mat <- matrix(rnorm(max*n),max,n)
V.mat <- Z.mat^2
U <- apply(V.mat[,1:3],1,sum)
V <- apply(V.mat[,4:5],1,sum)
X <- U/(U+V)

## 02
dice1 <- rep(NA,999)
dice2 <- rep(NA,999)
dice.X <- rep(NA,999)
p <- rep(1/6,6)
dice1 <- sample(seq(1,6,1),size=length(dice1),prob=p,replace=T)
dice2 <- sample(seq(1,6,1),size=length(dice2),prob=p,replace=T)
dice.X <- abs(dice1-dice2)
table(dice.X)
