import pandas as pd
import numpy as np

df = pd.read_csv("/content/seoul_cctv_test.csv", encoding='euc-kr')

dfsum = df['소계'].str.replace(',', '').astype(float).fillna(0).to_numpy()

mysum = df.drop(['기관명', '소계'], axis=1)
for i in mysum.columns:
    try:
        mysum[i] = mysum[i].fillna(0).astype(float)
    except:
        mysum[i] = mysum[i].str.replace(',', '').astype(float).fillna(0)
mysum = mysum.sum(axis=1).to_numpy()
print('데이터의 소계와 실제 데이터 값의 합이 동일한가?', np.array_equiv(dfsum, mysum))
print(dfsum - mysum)
