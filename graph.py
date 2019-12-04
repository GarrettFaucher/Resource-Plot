import matplotlib.pyplot as plt # Install matplotlib using pip
import pandas as pd # Install pandas using pip
import sys

# Store command line arguments in variables
filename = sys.argv[1] # Name of file to be used
type = sys.argv[2] # Type of graph to be used
color = sys.argv[3] # Color of points to be used

df = pd.read_csv('../' + filename) # Importing a DataFrame from CSV file

# Determining what graph will look like
# One column needs to be named x, and another y
if type == 'bar':
    df.plot(kind='bar',x='x',y='y',color=color)
elif type == 'line':
    df.plot(kind='line',x='x',y='y',color=color)
elif type == 'scatter':
    df.plot(kind='scatter',x='x',y='y',color=color)

plt.show()
