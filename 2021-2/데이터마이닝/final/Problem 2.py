import csv
import numpy as np
from sklearn.neural_network import MLPClassifier
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

file = open("/content/subway_0.csv","r", encoding="euc-kr")
data = csv.reader(file)
next(data)

X = []
y = []

for row in data:
    X.append([float(row[3]),float(row[4])])
    y.append(row[1])

file.close

model = MLPClassifier(max_iter=500, random_state=42)
model.fit(X, y)

a = 20000
b = 15000

print("승차총승객수가", a, "명이고, 하차총승객수가", b, "명일 때 열차는", model.predict([[a,b]]), "호선으로 예측할 수 있다.")
