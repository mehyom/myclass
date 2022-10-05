import csv
import numpy as np
from sklearn.linear_model import LinearRegression

file = open("subway.csv","r", encoding="euc-kr")
data = csv.reader(file)
next(data)

x = []
y = []

for row in data:
    if row[0] != '' :
        x.append([int(row[0])])
        y.append(int(row[1]))

file.close

model = LinearRegression()
model.fit(x, y)

y_2000 = int(model.predict([[2000]]))
y_2001 = int(model.predict([[2001]]))
y_2002 = int(model.predict([[2002]]))

print("2000년도는", y_2000, ", 2001년도는", y_2001, ", 2002년도는", y_2002, "로 예측 된다.")
