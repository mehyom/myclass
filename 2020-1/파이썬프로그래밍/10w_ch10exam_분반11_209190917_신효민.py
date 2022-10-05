#성신여자대학교 파이썬 프로그래밍 10주차 과제
#20190917 통계학과 신효민


#1
domain = {"kr":"대한민국", "us":"미국", "jp":"일본", "de":"독일",
          "sk":"슬로바키아", "hu":"헝가리", "no":"노르웨이"} # 딕셔너리 초기화

for key in domain.keys(): # 모든 key에 대해서
    print("%s: %s" %(key, domain[key])) # key와 value 출력


#2
problems  = {'파이썬': '최근에 가장 떠오르는 프로그래밍 언어',
                '변수': '데이터를 저장하는 메모리 공간',
                '함수': '작업을 수행하는 문장들의 집합에 이름을 붙인 것',
                '리스트': '서로 관련이 없는 항목들의 모임',
                } # 딕셔너리 초기화

def show_words(problems): 
    i = 0 # 문항 번호
    for key in problems.keys(): # 모든 key에 대해서
        i = i + 1 # 문항 번호를 추가해가며
        print("(%d)%s" %(i, key), end = " ") # 문항 번호 key값 출력
    print("")

for meaning in problems.values():
    print("다음은 어떤 단어에 대한 설명일까요? ")
    print("\""+meaning+"\"")
    correct = False
    while not correct:
        show_words(problems)
        guessed_word = input("")    
        if problems[guessed_word] == meaning:
            print("정답입니다. !")
            correct = True
        else:
            print("정답이 아닙니다.")
