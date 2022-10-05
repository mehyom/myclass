import numpy as np
data = [(0.563, 76, "KT"),(0.522,71,"Doosan"),(0.563,76,"Samsung"),(0.554,72,"LG"),(0.511,70,"Kiwoom")]

a, b = np.array(data, dtype=[('rate', 'f4'), ('win', 'i4'), ('team', 'S10')]), np.zeros(5, dtype=[('rank','i4'), ('win', 'f4'), ('lose', 'i4'), ('team', 'S10')])
for i in range(0,len(data)):
   b[i][0], b[i][1], b[i][2], b[i][3] = i, data[i][1], round(data[i][1]/data[i][0]*(1-data[i][0])), data[i][2]

print(a)
print(b)
print(a.dtype)
print(b.dtype)
