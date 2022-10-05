import csv
import numpy as np

file = open("/content/student_health_3.csv","r", encoding="euc-kr")
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

from sklearn.model_selection import train_test_split
X, X_val, y, y_val = train_test_split(X,y,test_size=0.2,shuffle=True,stratify=y,random_state=42)

from sklearn.cluster import KMeans
kms = KMeans(n_clusters=2, random_state=42).fit(X)

print(kms.labels_)
print(kms.score(X_val))
print(kms.predict([[117,25,100,60],[140,35,110,70]]))
print(kms.cluster_centers_)
