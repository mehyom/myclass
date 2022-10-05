#성신여자대학교 파이썬 프로그래밍 2주차 과제
#20190917 통계학과 신효민

#1
import random # 랜덤 함수 호출
x = random.randint(1, 19) # 1부터 19까지 중 숫자를 랜덤하게 x에 초기화
y = random.randint(1, 19) # 1부터 19까지 중 숫자를 랜덤하게 y에 초기화
ans = 0 # ans를 0으로 초기화

print("다음의 곱셈의 정확한 답을 맞춰보세요!:")
while ans != x * y : # ans가 곱셈의 정답이 될 때까지
    print(str(x), "x", str(y), "은", end = " ")
    ans = int(input()) # 사용자에게서 답안을 입력 받아 ans에 초기화
print(ans, "정답입니다!") # 곱셈의 정답을 맞췄을 때 출력


#2 - 1 (첫 번째 방법)
x = "x" # x를 정수나 "stop"이 아닌 다른 값으로 초기화
sum = 0 # sum을 0으로 초기화

while True : # break 될 때까지 반복
    try:
        x = input("정수를 입력하시오(종료 : stop): ") #사용자에게 x를 입력 받아
        sum += int(x) # 정수로 변환한 후 sum에 더해줌
    except ValueError: # ValueError가 났을 때
        if x.lower() == "stop" : # x에 stop이 입력 되었을 시
            break #반복문의 반복을 멈춤
print("합은 ", sum, "입니다.") # sum을 출력

#2 - 2 (두 번째 방법)

x = "x" # x를 정수나 "stop"이 아닌 다른 값으로 초기화
sum = 0 # sum을 0으로 초기화

while True : # break 될 때까지 반복
        x = input("정수를 입력하시오(종료 : stop): ") #사용자에게 x를 입력 받아
        if x ==  "stop" : # x가 stop이면
            break # 정지하고
        sum += int(x) # 아니면 x를 정수로 변환한 후 sum에 더해줌
print("합은 ", sum, "입니다.") # sum을 출력


#3
x = int(input("출력할 별의 줄 수 를 입력해주세요.: ")) # x를 사용자에게 입력 받음

for i in range(0, 2): # i는 0값을 가지고 그 다음 반복에서 1 값을 가짐
    for j in range(1, x+1): # j는 1~x까지의 값을 돌아가며 가짐
        if i == 0: # 첫 번째 반복에서 조건을 만족
            print("")
            print("*" * j, end = "") # *을 1개~x개까지 출력함
        else : # 두 번째 반복 시
            print("")
            print("*" * (x-j), end = "") # *을 x개~1개까지 출력함


#4
s = input("문자를 입력하세요.: ") # 사용자에게 문자열을 입력 받음
print("입력받은 문자열 :", s, "입력받은 문자열의 역순", end = " ")
for i in range(0, len(s)): # 문자열의 길이만큼 돌아가며 i는 0~len(s)-1값을 돌아가며 가짐
    print(s[len(s)-i:len(s)-i+1], end = "") # 문자열을 역순으로 출력
