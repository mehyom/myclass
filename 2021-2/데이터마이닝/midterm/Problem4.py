import csv
import numpy as np
from sklearn.neighbors import KNeighborsClassifier

file = open("park.csv","r", encoding="euc-kr")
data = csv.reader(file)
next(data)

x = []
y = []

for row in data:
    if row[2] != '' and row[3] != '' and row[4] != '':
        x.append([float(row[2]),float(row[3]),float(row[4])])
        y.append(row[1])

file.close

model = KNeighborsClassifier(n_neighbors=4)
model.fit(x, y)

real = model.predict([[1500000, 20000, 500000]])
print(real)
