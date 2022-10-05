def iammath(sym, *args):
    result = 0
    try:
        num = []
        for i in args:
            num.append(float(i))
    except:
        print("입력이 바르지 않습니다.")
    else:
      if sym == '+':
          for i in range(len(num)):
              result += num[i]
          return round(result,6)
      elif sym == '-':
          for i in range(len(num)):
              if i == 0:
                  result += num[i]
              else:
                  result = result - num[i]
          return round(result,6)
      elif sym == '/':
          for i in range(len(num)):
              if i == 0:
                  result += num[i]
              elif num[i] == 0:
                  print("잘못된 입력이 있어 해당 숫자는 건너뛰고 계산합니다.")
              else:
                  result = result / num[i]
          return round(result,6)
      elif sym == '*':
          for i in range(len(num)):
              if i == 0:
                  result += num[i]
              else:
                  result = result * num[i]
          return round(result,6)
      else:
          print("입력이 바르지 않습니다.")
x = iammath('+',1,2,3,4,5,6,7,8,9)
print(x)
x = iammath('/',7,8,9)
print(x)
x = iammath('*',1.23456789,9)
print(x)
