import csv
import numpy as np
from sklearn.neighbors import KNeighborsClassifier

file = open("/content/subway_1.csv","r", encoding="euc-kr")
data = csv.reader(file)
next(data)

X = []
y = []

for row in data:
    X.append([float(row[3]),float(row[4])])
    y.append(row[1])

file.close

model = KNeighborsClassifier(n_neighbors=8)
model.fit(X, y)

a = 10000
b = 10000

print("승차총승객수가", a, "명이고, 하차총승객수가", b, "명일 때 열차는", model.predict([[a,b]]), "호선으로 예측할 수 있다.")
