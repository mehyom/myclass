x, y, a = map(int, input("두 개의 숫자와 그 합을 비교할 숫자를 차례로 입력해주세요 (구분은 \" \"로 한다): ").split(" "))
z = x + y
print("내가 계산한 {:d}와 {:d}의 덧셈 결과값은 {:d}이며 실제 {:d}와 비교 시 동일 여부는 {}이다.".format(x, y, z, a, a == z))
