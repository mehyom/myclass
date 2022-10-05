import numpy as np
x = np.arange(62500)
x = np.reshape(x, (100, 25, 25))
x_avg = x.mean(axis = 0)
np.savetxt('test.csv', x_avg, delimiter=',', fmt='%1.3f')
