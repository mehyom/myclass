import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

data = np.loadtxt("airtravel.csv", delimiter=",",dtype="str")
index = data[1:,0]
columns = data[0,1:]
df = pd.DataFrame(data[1:,1:], index=index, columns=columns).astype('int').T
plt.figure(figsize=(24,5))
ax = sns.heatmap(df)
plt.show()
