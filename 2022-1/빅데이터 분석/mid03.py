import pandas as pd
import numpy as np
df1 = pd.DataFrame(np.ones((2,3)), index=list(range(0, 4, 2)), columns=list(range(0, 6, 2)))
df2 = pd.DataFrame(np.ones((3,2)), index=list(range(0, 6, 2)), columns=list(range(0, 4, 2)))
df3 = df1+df2
df3[6], df3[8], df3[10] = np.ones((3,1)), np.nan*3, np.ones((3,1))
df3.loc[6], df3.loc[8], df3.loc[10], df3.loc[8][10], df3.loc[6][8] = np.ones(6), np.nan*6, np.ones(6), 1, np.nan
print(df3)
