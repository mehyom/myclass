import numpy as np
a = np.zeros(3, dtype=[('a', 'f4'), ('b', 'i4'), ('c', 'S10')])
a = np.append(a, np.zeros(10, dtype=[('a', 'f4'), ('b', 'i4'), ('c', 'S10')]))
for i in range(len(a)):
     k = i + 1
     a[i]['a'] = k / 2
     a[i]['b'] = k * 2
     a[i]['c'] = 'a' * k
print(a)
