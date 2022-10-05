import csv
import numpy as np
import matplotlib.pyplot as plt

file = open("housing.csv","r", encoding="euc-kr")
data = csv.reader(file)
next(data)

floor = []
price = []

for row in data:
    if row[1] != '' and row[4] != '':
        floor.append(int(row[1]))
        price.append(int(row[4]))

plt.title("Scatter Plot")
plt.scatter(floor,price)
plt.xlabel("Floor")
plt.ylabel("Price")
plt.grid()
plt.show()

print("층수와 가격의 상관계수는", np.corrcoef(floor,price)[0,1], "이다.")
