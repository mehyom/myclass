x = input("입력값 1:")
y = input("입력값 2:")

import math
try:
   (x, y) = map(int, (x, y))
except:
   z = "구할 수 없으며, x와 y는 정수가 아닌 올바르지 않은 입력값"
else:
   z = int(math.pow(x, y))

print("x의 y 제곱 결과값은", z, "이다.")
