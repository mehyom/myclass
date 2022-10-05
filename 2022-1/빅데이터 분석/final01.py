import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("zillow.csv", dtype='float')
data = df[[' "Zip"', ' "List Price ($)"']].astype('int')
x = list(set(data[' "Zip"']))
y = data.groupby([' "Zip"']).mean()[' "List Price ($)"']
plt.bar(x, y[x])
plt.xlabel('zip code')
plt.ylabel('price')
plt.show()
