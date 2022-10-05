#성신여자대학교 파이썬 프로그래밍 9주차 과제
#20190917 통계학과 신효민


#1
avglist = [] # 정수 리스트 초기화
n = 5 # 리스트 사이즈
myavg = 0 # 평균 초기화

for i in range(0, n):
    x = int(input("정수를 입력하시오: ")) # 리스트 사이즈만큼 정수 입력 받음
    avglist.append(x) # 리스트에 입력받은 정수 추가

for i in range(0, n):
    myavg += avglist[i]/len(avglist) #평균 구하기

print("평균=%.1f"%myavg) #프린트


#2
heroes = ["아이언맨", "토르", "헐크", "스칼렛 위치"] # 히어로 리스트 초기화

myhero = input("자신이 히어로라고 생각하는 사람은? ") # 사용자에게 입력 받음

if myhero in heroes: # 사용자의 히어로가 리스트에 존재할 때
    print("당신이 생각하는 %s는 우리의 히어로입니다."%myhero)
else : # 아닐 
    print("당신이 생각하는 %s는 우리의 히어로가 아닙니다."%myhero)
