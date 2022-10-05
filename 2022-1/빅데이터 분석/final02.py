import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import scipy.stats as stats

df = pd.read_csv("nile.csv", dtype='float')
data = df[' "Flood"']
mu, std = stats.norm.fit(data)
df_lins = np.linspace(min(data),max(data), 100)
df_norm = stats.norm.pdf(df_lins, mu, std)

plt.hist(data, density=True, bins=30)
plt.plot(df_lins, df_norm, 'orange')
plt.xlabel('Flood')
plt.ylabel('density')
t = 'Nile(' + str(len(data)) + ')'
plt.title(t)
plt.show()
