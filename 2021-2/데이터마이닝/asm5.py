import csv
import numpy as np
from sklearn.neighbors import KNeighborsClassifier

file = open("/content/student_health_2.csv","r", encoding="euc-kr")
data = csv.reader(file)
next(data)

x = []
y = []

for row in data:
    x.append([float(row[15]),float(row[16])])
    y.append(row[11])

file.close

model = KNeighborsClassifier(n_neighbors=8)
model.fit(x, y)

real = model.predict([[150, 45]])
print(real)
