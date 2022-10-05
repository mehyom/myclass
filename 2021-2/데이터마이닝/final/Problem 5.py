import csv
import matplotlib.pyplot as plt
import numpy as np
from sklearn import linear_model

file = open("/content/nofare1.csv","r", encoding="euc-kr")
data = csv.reader(file)
next(data)

X = []
y = []

for row in data:
    X.append([float(row[3])])
    y.append([float(row[4])])

file.close

model = linear_model.LinearRegression()
model.fit(X, y)

plt.scatter(X, y, s=7, color="blue")
plt.plot(X, model.predict(X), color="orange")

plt.show()

a = 10000

print("총승차인원이", a, "명일 때 총하차인원은 약", model.predict([[a]]), "명이다.")
