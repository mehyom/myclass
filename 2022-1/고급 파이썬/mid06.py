class mathop:
    def mul(self, num1, num2):
        return num1 * num2

    def div(self, num1, num2):
        if num2 == 0:
            print("error. second number cannot be 0")
        else:
            return num1 / num2

    def add(self, num1, num2):
        return num1 + num2

    def sub(self, num1, num2):
        return num1 - num2

mathop = mathop()
print(mathop.mul(1,2))
print(mathop.div(1,2))
print(mathop.add(1,6.5))
print(mathop.sub(2,2.1))
