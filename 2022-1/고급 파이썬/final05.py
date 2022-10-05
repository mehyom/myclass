import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("/content/seoul_0.csv", encoding='euc-kr')
df = df[['자치구명', '건물주용도']]
df = df[df['자치구명'] == '성북구']
df = df.dropna()
count = df.groupby(['건물주용도']).count().T
for name in list(set(df['건물주용도'])):
    print(name, '거래체결수: ', count[name][0], '회')
