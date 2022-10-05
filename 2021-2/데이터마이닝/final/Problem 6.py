import csv
import numpy as np
from sklearn.linear_model import LogisticRegression

file = open("/content/nofare2.csv","r", encoding="euc-kr")
data = csv.reader(file)
next(data)

X = []
y = []

for row in data:
    X.append([float(row[3].replace(",","")),float(row[4].replace(",",""))])
    y.append(row[2])

model = LogisticRegression(random_state=42)
model.fit(X, y)

a = 13000
b = 12000

print("총승차인원이", a, "명이고, 총하차인원이", b, "명일 때 열차의 위치는", model.predict([[a,b]]), "번째 역이다.")
