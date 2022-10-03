import linked_queue

def remover(que, k):
    for i in range(k - 1):
        que.enqueue(que.dequeue())
    return que.dequeue()

n = int(input())
k = int(input())
que = linked_queue.LinkedQueue()

for i in range(n):
    que.enqueue(i + 1)

for i in range(n):
    print(remover(que, k), end=" ")
