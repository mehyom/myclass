#성신여자대학교 파이썬 프로그래밍 7주차 과제
#20190917 통계학과 신효민


#1
# 사용자에게 점수를 입력 받음
pythonScore = int(input("파이썬 프로그래밍 최종 점수를 입력하시오 : "))
itsummaryScore = int(input("IT 개론 최종 점수를 입력하시오 : "))
probabilityScore = int(input("확률과 통계 최종 점수를 입력하시오 : "))
digitalScore = int(input("디지털 컨텐츠 최종 점수를 입력하시오 : "))

def printGrade(score): # 점수를 계산해 출력해주는 함수
    if score >= 90 :
        grade = 'A'
    elif score >= 80 :
        grade = 'B'
    elif score >= 70 :
        grade = 'C'
    elif score >= 60 :
        grade = 'D'
    else : grade = 'F'
    
    print(grade)
    
print(" 파이썬 프로그래밍 등급 :", end = " ")
printGrade(pythonScore)
print(" IT 개론 등급 :", end = " ")
printGrade(itsummaryScore)
print(" 확률과 통계 등급 :", end = " ")
printGrade(probabilityScore)
print(" 디지털 콘텐츠 등급 :", end = " ")
printGrade(digitalScore)


#2
# 커피 재고 변수 
coffeeStock = 5
latteStock = 5
capuccinoStock = 5

# 커피 금액 변수
coffeePrice = 2000
lattePrice = 3000
capuccinoPrice = 2500

# 잔액 변수
remainMoney = 0

# 사용자가 투입한 돈
inputMoney = int(input("돈을 투입해주세요! : "))
strInputMoney = str(inputMoney)              # 금액 단위에 , 표시를 위해 str() 사용
print("투입 금액 : "+strInputMoney[:-3]+","+strInputMoney[-3:], "원")

def choiceCoffee(inputMoney) :
    global coffeeStock
    global latteStock
    global capuccinoStock
    remainMoney = inputMoney  
    print("-"*60)
    print("커피 : 2,000원 \n라떼 : 3,000원 \n카푸치노 : 2,500원")
    print("-"*60)

    coffeeChoice = input("커피(c) 또는 라떼(l) 또는 카푸치노(n) 를 선택해주세요 : ")
    if coffeeChoice == "c" or coffeeChoice == "커피" :        # 사용자가 커피를 선택한 경우 
        print("커피를 선택하셨습니다.")   
        remainMoney -= coffeePrice                                # 커피 선택에 따른 잔액 계산  
        coffeeStock -= 1                                               # 커피 재고 업데이트 
    elif coffeeChoice == "l" or coffeeChoice == "라떼" :       # 사용자가 라떼를 선택한 경우
        print("라떼를 선택하셨습니다.")
        remainMoney -= lattePrice                                 # 라떼 선택에 따른 잔액 계산  
        latteStock -= 1                                                # 라떼 재고 업데이트
    elif coffeeChoice == "n" or coffeeChoice == "카푸치노" :       # 사용자가 카푸치노를 선택한 경우
        print("라떼를 선택하셨습니다.")
        remainMoney -= capuccinoPrice                                 # 카푸치노 선택에 따른 잔액 계산  
        capuccinoStock -= 1                                                # 카푸치노 재고 업데이트 

    if remainMoney < 0 :                                            # 잔액이 부족한 경우 
        print("투입하신 돈이 부족합니다. 다음에 다시 이용해주세요!")
        print("현재 커피 재고는 : ", coffeeStock,"개 이며, 라떼 재고는 ",latteStock, "개 이며 카푸치노 재고는 ",capuccinoStock, "개 입니다. ")
    elif remainMoney >= 0 :                                         # 잔액이 있는 경우
        strRemainMoney = str(remainMoney)
        print("잔액은 ", strRemainMoney[:-3]+","+strRemainMoney[-3:], "원입니다. ")
    return remainMoney

def continueMachine(remainMoney) :
    continueStr = input("자판기를 계속 이용하시겠습니까? (y/n) : ")
    if continueStr != 'y' and continueStr != 'Y' :
        strRemainMoney = str(remainMoney)
        print("현재 커피 재고는 : ", coffeeStock,"개 이며, 라떼 재고는 ",latteStock, "개 이며 카푸치노 재고는 ",capuccinoStock, "개 입니다. ")
        print("잔액은 ", strRemainMoney[:-3]+","+strRemainMoney[-3:], "원입니다. ")
        return 0
    return 1

remainMoney = inputMoney# 잔액변수에 투입한 돈 저장
while remainMoney > 0:
    remainMoney = choiceCoffee(remainMoney)
    if 0 == continueMachine(remainMoney) :
        break
