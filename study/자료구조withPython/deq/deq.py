class Deque(object):
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return not bool(self.items)

    def enqueue(self, item):
        self.items.insert(0, item)

    def dequeue(self):
        value = self.items.pop()
        if value is not None:
            return value
        else:
            print("Queue is empty.")

    def size(self):
        return len(self.items)

    def peek(self):
        if self.items:
            return self.items[-1]
        else:
            print("Queue is empty.")

    def __repr__(self):
        return repr(self.items)

    def enqueue_back(self, item):
        self.items.append(item)

    def dequeue_front(self):
        value = self.items.pop(0)
        if value is not None:
            return value
        else:
            print("Deque is empty.")
