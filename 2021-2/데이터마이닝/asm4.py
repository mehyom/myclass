import pandas as pd
data = pd.read_csv('/content/random_number.csv',header=None)
from sklearn.metrics import confusion_matrix
confusion_matrix(data[0],data[1])
acc = (6847+0+849)/10000
err = (0+0+1559+0+0+745)/10000
