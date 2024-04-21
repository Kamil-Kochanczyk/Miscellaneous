import pandas as pd

dataframe = pd.read_csv('/home/kamil/Desktop/pokemon.csv')

"""
print(dataframe)
print()
print(dataframe.head(3))
print()
print(dataframe.tail(3))
print()
"""

"""
print(dataframe.columns)
print()
print(dataframe['Name'])
print()
print(dataframe[['Name', 'Speed', 'HP']])
print()
print(dataframe[['Name', 'Speed', 'HP']][1:4])
print()
print(dataframe.iloc[1:4])
print()
print(dataframe.iloc[3, 1])
print()
"""

"""
for index, row in dataframe.iterrows():
    if index <= 3:
        print(index, '\n', row[['Name', 'Speed', 'HP']], '\n')

print(dataframe.loc[dataframe['Speed'] >= 100][['Generation', 'Legendary']][1:4])
print()
"""

"""
print(dataframe.describe())
print()
print(dataframe.sort_values('Name', ascending=False))
print()
print(dataframe.sort_values('Speed')[['Name', 'Speed']])
print()
"""

"""
dataframe['Total'] = dataframe['HP'] + dataframe['Attack'] + dataframe['Defense'] + dataframe['Sp. Atk'] + dataframe['Sp. Def'] + dataframe['Speed']
print(dataframe)
print()

dataframe = dataframe.drop(columns=['Total'])
print(dataframe)
print()
"""

"""
start = 4
end = 10
dataframe['Tot'] = dataframe.iloc[:, start:end].sum(axis=1)
print(dataframe)
print()

columns = list(dataframe.columns)
print(columns)
print()

dataframe = dataframe[columns[0:start] + [columns[-1]] + columns[start:(len(columns) - 1)]]
print(dataframe)
print()

dataframe.to_csv('/home/kamil/Desktop/modified.csv', index=False)
"""

"""
filtered = dataframe.loc[(dataframe['HP'] >= 100) & (dataframe['Speed'] >= 120)]
filtered.reset_index(drop=True, inplace=True)

filtered.to_csv('/home/kamil/Desktop/filtered.csv')

filtered.loc[filtered['Speed'] >= 130, ['Generation', 'Legendary']] = [-1, "Unknown"]
print(filtered)
print()
"""

"""
print(dataframe.loc[~dataframe['Name'].str.contains('Mega')])
print()
print(dataframe.loc[dataframe['Name'].str.contains('^Pi[a:z]*', regex=True)])
print()
"""

"""
print(dataframe.groupby(['Type 1']).mean().sort_values('Speed', ascending=False))
print()
print(dataframe.groupby(['Type 1']).sum().sort_values('Speed', ascending=False))
print()
print(dataframe.groupby(['Type 1']).count().sort_values('Speed', ascending=False))
print()
print(dataframe.loc[dataframe['Type 1'] == 'Flying'])
print()
"""

"""
counter = 0
for df in pd.read_csv('/home/kamil/Desktop/pokemon.csv', chunksize=5):
    if counter <= 5:
        print(df)
        print()
        counter += 1
"""
