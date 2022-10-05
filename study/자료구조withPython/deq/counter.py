from deq import Deque

n, m = map(int, input().split())
s = list(map(int, input().split()))
q = Deque()
for i in range(1, n+1):
    q.enqueue_back(i)
count = 0

def opr1():
    return q.dequeue_front()

def opr2():
    global count
    q.enqueue_back(q.dequeue_front())
    count += 1

def opr3():
    global count
    q.enqueue(q.dequeue())
    count += 1

for i in range(m):
    idx = q.items.index(s[i])
    if idx < len(q.items) - idx:
        while True:
            if s[i] == q.items[0]:
                opr1()
                break
            else:
                opr2()
    else:
        while True:
            if s[i] == q.items[0]:
                opr1()
                break
            else:
                opr3()

print(count)
