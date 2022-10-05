import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import scipy.stats as stats

df = pd.read_csv("/content/hw_25000.csv")
data = df[' "Height(Inches)"']
mu, std = stats.norm.fit(data)
df_lins = np.linspace(min(data),max(data), 100)
df_norm = stats.norm.pdf(df_lins, mu, std)

plt.hist(data, density=True, bins=100)
plt.xlabel('Height(Inches)')
plt.ylabel('Columns')
plt.show()

plt.hist(data, density=True, bins=100)
plt.plot(df_lins, df_norm, 'orange')
plt.xlabel('Height(Inches)')
plt.ylabel('Columns')
plt.show()

plt.show()
