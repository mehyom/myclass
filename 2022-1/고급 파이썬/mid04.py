class mycalculation:
   def __init__(self, input1, input2):
      self.input1 = str(input1)
      self.input2 = str(input2)

   def cal(self):
      self.input3 = str(int(self.input1) * int(self.input2) + int(self.input1))
      return self.input3

test = mycalculation(2, 3)
print("현 클래스내에서의 입력값이 " + test.input1 + "과 " + test.input2 + "일 때 최종 값은 " + test.cal() + "이어야 함.")
