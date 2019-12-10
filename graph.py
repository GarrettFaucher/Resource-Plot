import matplotlib.pyplot as plt # Install matplotlib using pip
import matplotlib.animation as animation
import psutil
import sys

# Store command line arguments in variables
filename = sys.argv[1] # Name of file to be used
type = sys.argv[2] # Type of graph to be used
color = sys.argv[3] # Color of points to be used

fig = plt.figure()
axis1 = fig.add_subplot(1,1,1)

currentTime = 0;
times = []
usages = []

def animate(i):
    if (filename != "cpu"):
        data = open('../' + filename, 'r').read()
        lines = data.split('\n')
        xs = []
        ys = []
        for line in lines:
            if len(line) > 1:
                x, y = line.split(',')
                xs.append(float(x))
                ys.append(float(y))
        axis1.clear()
        axis1.set_ylabel('y')
        axis1.set_xlabel('x')
        axis1.set_title('Graphed Data from ' + filename)
        if type == 'bar':
            axis1.bar(xs, ys, color=color)
        elif type == 'line':
            axis1.plot(xs, ys, color=color)
        elif type == 'scatter':
            axis1.scatter(xs, ys, color=color)
    else:
        global times
        global usages
        global currentTime
        times.append(currentTime)
        usages.append(psutil.cpu_percent())
        axis1.clear()
        axis1.set_ylabel('CPU Usage (%)')
        axis1.set_xlabel('Time (seconds)')
        axis1.set_title('CPU Usage vs Time')
        plt.ylim(0, 100)
        axis1.plot(times, usages, color=color)
        currentTime += 0.1
        if (currentTime > 10):
            del times[0]
            del usages[0]

ani = animation.FuncAnimation(fig, animate, interval=100)
plt.show()
