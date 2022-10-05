import stack_with_node

data = []
num = int(input(""))

for i in range(num):
    val = int(input(""))
    data.append(val)

stack = stack_with_node.Stack()

for i in range(num):
    if data[i] == 0:
        if stack.isEmpty() is False:
            stack.pop()
    else:
        stack.push(data[i])

sum = 0

while stack.isEmpty() is False:
    sum += stack.pop()

print(sum)
