import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("/content/seoul_0.csv", encoding='euc-kr')
df = df[['자치구명','신고년도', '건물주용도', '물건금액']]
df = df[df['자치구명'] == '성북구']
df = df[df['신고년도'] == 2011]
df = df[(df['건물주용도']=='오피스텔') | (df['건물주용도']=='아파트') | (df['건물주용도']=='단독주택')]
df = df[df['물건금액'] != 0]
df = df.dropna()

x = ['오피스텔', '아파트', '단독주택']
y = df.groupby(['건물주용도']).mean()['물건금액'] / 10000
plt.bar(x, y[x])
plt.xlabel('건물주용도')
plt.ylabel('물건금액(단위:만원)')
plt.show()
