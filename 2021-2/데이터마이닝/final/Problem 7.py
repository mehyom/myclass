import csv
import numpy as np
from sklearn.cluster import KMeans

file = open("/content/student_health_5.csv","r", encoding="euc-kr")
data = csv.reader(file)
next(data)

X = []
y = []

for row in data:
    X.append([float(row[15]),float(row[16])])
    if row[11] == '1' or row[11] == '2' or row[11] == '3':
        y.append(1)
    else:
        y.append(0)


model = KMeans(n_clusters=2, random_state=42)
model.fit(X)

result = model.labels_

cnt = 0

for idx in range(0,len(result)):
    if result[idx] == y[idx]:
        cnt += 1

print("정확도는", cnt/len(result), "이다.")
