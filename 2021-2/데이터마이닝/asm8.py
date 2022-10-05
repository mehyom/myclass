import csv
import numpy as np
from sklearn.neighbors import KNeighborsClassifier
from sklearn.neural_network import MLPClassifier
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

file = open("/content/student_health_2.csv","r", encoding="euc-kr")
data = csv.reader(file)
next(data)

X = []
y = []

for row in data:
    X.append([float(row[15]),float(row[16])])
    y.append(float(row[11]))

file.close

X_train, X_test, y_train, y_test = train_test_split(X, y, stratify=y, random_state=42, test_size=0.2)

scaler = StandardScaler()
scaler.fit(X_train)
X_train = scaler.transform(X_train)
X_test = scaler.transform(X_test)

model = KNeighborsClassifier(n_neighbors=8)
model.fit(X_train,y_train)

print(model.score(X_test, y_test))

clf = MLPClassifier(random_state=42, max_iter=500)
clf.fit(X_train, y_train)

print(clf.score(X_test, y_test))
