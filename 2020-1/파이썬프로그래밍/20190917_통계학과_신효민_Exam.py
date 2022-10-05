#분반 : 11
#학번 : 20190917
#이름 : 신효민


#1.
def calc(firstOP, secondOP, operator):
    global result
    if operator == "+":
        return firstOP + secondOP
    elif operator == "-":
        return firstOP - secondOP
    elif operator == "*":
        return firstOP * secondOP
    elif operator == "/":
        return firstOP / secondOP
    else : return False

def calcPrint(operator, result):
    if result != False:
        print("연산 결과는 %.2f 입니다." %result)

print("-"*60)
print("간단한 계산기 프로그램")
print("-"*60)
firstOp = float(input("첫 번째 수를 입력하세요. : "))
secondOP = float(input("두 번째 수를 입력하세요. : "))
operator = input("계산할 연산자를 입력하세요(+, - , *, /) : ")
result = 0
        
result = calc(firstOp, secondOP, operator)
calcPrint(operator, result)


#2
count = 1
userId = ''
userPwd = ''
adminId = 'admin'
adminPwd = 'asdf123'

while True:
    if count >= 5:
        print("관리자 아이디나 비밀번호 입력 횟수가 초과되었습니다.")
        break
    else:     
        if userId == "":
            userId=input("관리자 아이디 입력 : ")
        
        elif userId != "" and userId != adminId:
            print("누적 오류 횟수: ", count, " 회")
            userId=input("관리자 아이디 입력 : ")
            count += 1
            
        elif userId == adminId:
            userPwd=input("관리자 비밀번호 입력 : ")
            
            if userPwd == adminPwd:
                print("로그인 성공!")
                break
        
            elif userPwd != adminPwd:
                print("누적 오류 횟수: ", count, " 회")
                print("관리자 비밀번호 재입력 ")
                count += 1
           

#3
def inputSum(start, end) :
    sum = start
    for i in range(start, end + 1):
        sum += i
    return sum

numStart = int(input("시작 숫자를 입력하세요. : "))
numEnd = int(input("끝 숫자를 입력하세요. : "))
average = (numStart + numEnd) / 2
print("두 숫자의 : %d, %d 의 중간 숫자는 %d" %(numStart, numEnd, average))
print("두 숫자의 누적 합은 ", inputSum(numStart, numEnd))


#4
i = 0
n = int(input("몇 개를 그릴까요?: "))
a = n // 2 + n % 2

while i < n :
    if i < a :
        k = 0
        while k < (a - n % 2) - i :
            print(" ", end = " ")
            k += 1
        k = 0
        while k < i * 2 + n % 2 :
            print("*", end = " ")
            k += 1
    else :
        k = 0
        while k < i- (a - n % 2) :
            print(" ", end = " ")
            k += 1
        k = 0
        while k < (n - i) * 2 - n % 2 :
            print("*", end = " ")
            k += 1

    print()
    i += 1
    

#5
def gugu():
    for i in range(1, 10):
        for j in range(1, 9):
            print("%d X %d = %-2d\t" %(10-j, i, i*(10-j)), end = "")
        print("\n")
gugu()
