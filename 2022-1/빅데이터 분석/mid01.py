import pandas as pd

df = pd.read_csv("/content/seoul_cctv.csv", encoding='euc-kr')
df.dropna(axis=0, inplace=True)
df.drop(['소계', '2011년 이전', '2013년', '2015년', '2017년'], axis=1, inplace=True)
for i in df.columns[1:]:
    df[i] = df[i].apply(lambda x: float(x)).apply(lambda x: 10 if x < 10 else x)
    
print(df)
