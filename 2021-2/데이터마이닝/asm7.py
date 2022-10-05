import csv
import numpy as np
from sklearn.linear_model import LogisticRegression

file = open("/content/student_health_3.csv","r", encoding="euc-kr")
data = csv.reader(file)
next(data)

X = []
y = []

for row in data:
    if row[15] != '' and row[16] != '' and row[23] != '' and row[24] != '':
        X.append([float(row[15]),float(row[16]),float(row[23]),float(row[24])])
        y.append(row[11])

model = LogisticRegression(random_state=0).fit(X, y)
print(model.score(X,y))
print(model.coef_)
