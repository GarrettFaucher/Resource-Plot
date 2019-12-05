import matplotlib.pyplot as plt # Install matplotlib using pip
import matplotlib.animation as animation
import pandas as pd # Install pandas using pip
import sys

# Store command line arguments in variables
filename = sys.argv[1] # Name of file to be used
type = sys.argv[2] # Type of graph to be used
color = sys.argv[3] # Color of points to be used

fig = plt.figure()
axis1 = fig.add_subplot(1,1,1)

def animate(i):
    data = open('../' + filename, 'r').read()
    lines = data.split('\n')
    xs = []
    ys = []
    for line in lines:
        if len(line) > 1:
            x, y = line.split(',')
            xs.append(x)
            ys.append(y)
    axis1.clear()
    if type == 'bar':
        axis1.bar(xs, ys, color=color)
    elif type == 'line':
        axis1.plot(xs, ys, color=color)
    elif type == 'scatter':
        axis1.scatter(xs, ys, color=color)

ani = animation.FuncAnimation(fig, animate, interval=100)
plt.show()
