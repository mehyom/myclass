number = [0, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, 3, 3, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 2, 4, 2, 4, 4, 3, 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 3, 4, 4, 1, 3, 4, 4, 2, 4, 2, 2, 4, 4, 2, 4, 3, 4, 4, 2, 4, 4, 2, 4, 4, 3, 4, 3, 4, 2, 4, 0, 3, 1, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 3, 4, 4, 4, 4, 3, 4, 4, 3, 2, 3, 4, 4, 4, 3]
import matplotlib.pyplot as plt

def count(number):
    counter = {}
    for n in number:
        if n in counter:
            counter[n] += 1
        else:
            counter[n] = 1
    return counter

def plot(counter):
    plt.bar(counter.keys(), counter.values(), width=0.5, color="blue")
    plt.savefig('plot.png')

plot(count(number))
