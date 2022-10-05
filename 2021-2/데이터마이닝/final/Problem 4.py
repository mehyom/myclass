import csv
import numpy as np
from sklearn.neighbors import KNeighborsClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.discriminant_analysis import QuadraticDiscriminantAnalysis

file = open("/content/subway_2.csv","r", encoding="euc-kr")
data = csv.reader(file)
next(data)

X = []
y = []

for row in data:
    X.append([float(row[3]),float(row[4])])
    y.append(row[1])

file.close

model_KNN = KNeighborsClassifier(n_neighbors=8)
model_KNN.fit(X, y)

model_LR = LogisticRegression()
model_LR.fit(X, y)

model_QDA = QuadraticDiscriminantAnalysis()
model_QDA.fit(X, y)

a = 30000
b = 30000

print("승차총승객수가", a, "명이고, 하차총승객수가", b, "명일 때 \n",
      "K-NN 분류에 따라 예측하면 열차는", model_KNN.predict([[a,b]]), "호선,\n",
      "Logistic Regression에 따라 예측하면 열차는", model_LR.predict([[a,b]]), "호선,\n",
      "QDA에 따라 예측하면 열차는", model_QDA.predict([[a,b]]), "호선이다.")      

print("K-NN 분류기의 정확률은", model_KNN.score(X, y),
      ", Logistic Regression의 정확률은", model_LR.score(X, y),
      ", QDA 기법의 정확률은", model_QDA.score(X, y), "이다.")
