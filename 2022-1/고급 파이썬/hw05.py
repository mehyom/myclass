import pandas as pd

df = pd.read_csv("stat_dist.csv")

dist = ['normal_dist', 'chi_square_dist', 'uniform_dist']
number = [10, 20, 30, 50, 100]

def summary(df):
    print('[통계량]  평균: {0:0.4f}   표준편차: {1:0.4f}   분산: {2:0.4f}   최대값: {3:0.4f}   최소값: {4:0.4f}'.format(df.mean(), df.std(), df.var(), df.max(), df.min()))
    print('[분위수]  10%: {0:0.4f}   30%: {1:0.4f}   50%: {2:0.4f}   70%: {3:0.4f}   90%: {4:0.4f}'.format(df.quantile(q=0.1), df.quantile(q=0.3), df.quantile(q=0.5), df.quantile(q=0.7), df.quantile(q=0.9)))

for distribution in dist:
    for n in number:
        data = df[distribution].sample(n)
        print('\n============================================================================================\n')
        print('{} 분포의 {}개 샘플에 대한 통계량'.format(distribution, data.shape))
        summary(data)
