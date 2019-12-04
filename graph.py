import matplotlib.pyplot as plt #TODO: Install matplotlib using pip
import pandas as pd #TODO: Install pandas using pip
import sys

# Store command line arguments in variables
filename = sys.argv[1]
type = sys.argv[2]
color = sys.argv[3]

df = pd.read_csv('../' + filename) # Importing a DataFrame from CSV file

if type == 'bar':
    df.plot(kind='bar',x='x',y='y',color=color)
elif type == 'line':
    df.plot(kind='line',x='x',y='y',color=color)
elif type == 'scatter':
    df.plot(kind='scatter',x='x',y='y',color=color)

plt.show()
