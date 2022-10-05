import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

df = pd.read_csv("London.csv")
data = df[['House Type', 'Price', 'Area in sq ft']]
x = list(set(data['House Type']))
y = data.groupby(['House Type'])
plt.figure(figsize=(20,10))
leg = []
for htype in x:
    leg.append(htype)
    ax = sns.regplot(x=y.get_group(htype)['Price']/1000, 
                     y=y.get_group(htype)['Area in sq ft'], 
                     scatter_kws={'s':1})
plt.xlabel('Price(/1000)')
plt.legend(leg)
plt.show()
