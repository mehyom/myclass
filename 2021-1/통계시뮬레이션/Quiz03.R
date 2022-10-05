s.size <- 10000
x.mon <- runif(s.size,0,1)
y.mon <- runif(s.size,0,1)
theta.hat <- mean(sqrt(x.mon^2+y.mon^2))
theta.hat

pi <- 4*theta.hat
pi
