#성신여자대학교 파이썬 프로그래밍 3주차 과제
#20190917 통계학과 신효민


#1
x = int(input("x: ")) 
y = int(input("y: "))
print("두수의 합:", x + y)
print("두수의 차:", x - y)
print("두수의 곱:", x * y)
print("두수의 평균: %.2f"%((x + y) / 2))
print("큰수:", max(x, y))
print("작은수:", min(x, y))

#2
x = int(input("4자리 정수를 입력하시오: "))
num1 = x % 10
num2 = (x // 10) % 10
num3 = (x // 100) % 10
num4 = x // 1000
total = num1 + num2 + num3 + num4
print("각 자리수의 합:", total)

#3
import time
timeGMT = time.time()
x = int(time.time())  
hour = (x // 3600) % 24
minute = (x // 60) % 60
print("현재 시간(영국 그리니치 시각): " + str(hour) + "시 " + str(minute) + "분")
