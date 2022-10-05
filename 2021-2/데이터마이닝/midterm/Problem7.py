import csv
import numpy as np
from sklearn.metrics import confusion_matrix
import matplotlib.pyplot as plt

file = open("emotion.csv","r", encoding="euc-kr")
data = csv.reader(file)
next(data)

real = []
pred = []
for row in data:
    if row[0] != '' and row[1] != '':
        pred.append(row[0])
        real.append(row[1])

label = ['Happy','Sad','Angry']
cm = confusion_matrix(real,pred,labels=label)

import seaborn as sns
plt.figure(figsize=(4,3))
sns.heatmap(cm,annot=True,cmap='Blues',xticklabels=label,yticklabels=label)
plt.title("<CONFUSION MATRIX>")
plt.ylabel('Real')
plt.xlabel('Prediction')
plt.show()
