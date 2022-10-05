import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("/content/food_1.csv", encoding='euc-kr')
data = df.loc[[1, 3, 6]].drop(columns = ['시도별', '품목별'])
for n in [1, 3, 6]:
    data.loc[n] = data.loc[n]/data.loc[n][0]*100

plt.figure(figsize=(20,5))
x_values = data.columns
plt.plot(x_values, data.loc[1])
plt.plot(x_values, data.loc[3])
plt.plot(x_values, data.loc[6])
plt.legend(['Seoul', 'Dae-gu', 'Daejeon'])
plt.show()
