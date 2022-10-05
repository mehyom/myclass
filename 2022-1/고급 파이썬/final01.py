import numpy as np
import pandas as pd

data = np.loadtxt("/content/hurricanes.csv", delimiter=",",dtype="str")
index = data[:,0]
columns = data[0,:]
df = pd.DataFrame(data, index=index, columns=columns) .drop(['"Month"'],axis='columns').drop(['"Month"'],axis='rows').astype('float')
df = np.where(df >= 5, 1, 0)
index = np.delete(index, 0)
myindex = []
for i in index:
    myindex.append([i])
columns = np.reshape(columns,(1,13))
arr = np.append(myindex, df, axis=1)
arr = np.append(columns, arr, axis=0)
np.savetxt("hurricanes_threshold.csv", np.array(arr, dtype='str'), fmt='%s', delimiter=",")
