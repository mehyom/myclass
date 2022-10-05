import pandas as pd
import numpy as np

class seoul_cctv:
    def __init__(self):
        self.data = []
        self.newdata = []
        self.colname = []
    
    def step_one(self, path='/content/seoul_cctv.csv'):
        self.data = pd.read_csv(path, encoding='euc-kr')
        print(self.data)
        self.colname = self.data.columns.to_numpy()
        self.colname = np.append(self.colname, '소계와 데이터 비교')
        self.colname = np.reshape(self.colname, (1, 11))
        for i in self.data.columns:
            try:
                self.data[i] = self.data[i].fillna(0).astype(int)
            except:
                self.data[i] = self.data[i].str.replace(',', '').fillna(0).astype(int)
        self.data = self.data.to_numpy()

    def step_two(self):
        for i in range(len(self.data)):
            compare = np.array_equiv(self.data[i][1], np.delete(self.data, [0,1], axis=1).sum(axis=1)[i])
            compare = str(compare)
            print(i, compare)
            self.newdata.append(compare)
        self.newdata = np.reshape(self.newdata, (25, 1))

    def step_three(self):
        result = np.concatenate((self.data, self.newdata), axis=1)
        result = np.concatenate((self.colname, result), axis=0)
        np.savetxt('seoul_cctv_result.csv', result, delimiter=',', fmt='%s')

cctv = seoul_cctv()
cctv.step_one()
print('\n\n\n')
cctv.step_two()
cctv.step_three()
