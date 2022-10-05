import math

def sigmoid(x):
    return 1 / (1 + math.exp(-x))
def tanh(x):
    return (math.exp(x) - math.exp(-x)) / (math.exp(x) + math.exp(-x))
def ReLU(x):
    if x > 0:
        return x
    else:
        return 0
def Leaky_ReLU(x):
    if x > 0.01 * x:
        return x
    else:
        return 0.01 * x
