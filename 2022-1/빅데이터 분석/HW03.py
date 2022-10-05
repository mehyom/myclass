import pandas as pd
import numpy as np

df = pd.read_csv("/content/news.csv", engine='python')[['title','text','label']]
fake = df.groupby('label').get_group('FAKE')
real = df.groupby('label').get_group('REAL')
print('# 1 \n* fake label: ' + str(len(fake)) + '개\n* real label: ' + str(len(real)) + '개\n')
df.groupby('label')
def counter(data):
    n = []
    for txt in data:
        n.append(len(txt.split(' ')))
    return str(round(np.mean(n), 4))
print('# 2 \n* fake news title: ' + counter(fake['title']) + '개     fake news text: ' + counter(fake['text']) + '개\n' +
      '* real news title: ' + counter(real['title']) + '개     real news text: ' + counter(real['text']) + '개')
