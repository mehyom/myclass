class Node(object):
    def __init__(self, value=None, pointer=None):
        self.value = value
        self.pointer = pointer


class Stack(object):
    def __init__(self):
        self.head = None
        self.count = 0

    def isEmpty(self):
        return not bool(self.head)

    def push(self, item):
        self.head = Node(item, self.head)
        self.count += 1

    def pop(self):
        if self.count > 0 and self.head:
            node = self.head
            self.head = node.pointer
            self.count -= 1
            return node.value
        else:
            print("Stack is empty.")

    def peek(self):
        if self.count > 0 and self.head:
            return self.head.value
        else:
            print("Stack is empty.")

    def size(self):
        # node = self.head
        # count = 0
        # while node:
        #     count += 1
        #     node = node.pointer
        # return count
        return self.count

    def _printList(self):
        node = self.head
        while node:
            print(node.value, end=" ")
            node = node.pointer
        print()
