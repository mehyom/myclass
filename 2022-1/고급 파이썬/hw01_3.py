x = input("입력값 1:")
y = input("입력값 2:")

if x == "":
    x = 1

if y == "":
    y = 100

try:
    (x, y) = map(int, (x, y))
except:
    print("입력값은 정수만 가능합니다. 올바른 입력을 해주세요.")
else:
    if x > y:
        print("두 번째 입력값은 첫 번째 입력값보다 커야합니다.")
    else:
        while x <= y:
            print(x)
            x += 1
