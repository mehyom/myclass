import csv
import numpy as np

file = open("/content/student_health_3 .csv","r", encoding="euc-kr")
data = csv.reader(file)
next(data)

X = []
y = []

for row in data:
    if row[15] != '' and row[16] != '' and row[23] != '' and row[24] != '':
        X.append([float(row[15]),float(row[16]),float(row[23]),float(row[24])])
        if row[11] == '1' or row[11] == '2' or row[11] == '3':
          y.append('Class 1')
        else:
          y.append('Class 2')

from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
lda = LinearDiscriminantAnalysis()
lda.fit(X, y)
print(lda.score(X,y))
print(lda.coef_)

from sklearn.discriminant_analysis import QuadraticDiscriminantAnalysis
qda = QuadraticDiscriminantAnalysis()
qda.fit(X, y)
print(qda.score(X,y))
print(qda.means_)
