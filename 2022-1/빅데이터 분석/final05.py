import pandas as pd

df = pd.read_csv("London.csv")
df['No. of rooms'] = df[['No. of Bedrooms', 'No. of Bathrooms', 'No. of Receptions']].sum(axis=1)
data = df[['House Type', 'Price', 'Area in sq ft', 'No. of rooms']]
x = list(set(data['House Type']))
y = round(data.groupby(['House Type']).mean(),2)

for htype in x:
    print('========{0:=^20}========'.format(htype))
    print('mean of Price:        ', y['Price'][htype])
    print('mean of Area in sq ft:', y['Area in sq ft'][htype])
    print('mean of No. of rooms: ', y['No. of rooms'][htype])
    print('')
