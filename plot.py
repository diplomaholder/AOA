import matplotlib.pyplot as plt
import csv

x = []
y1 = []
y2 = []
for i in range(5000,1000001,1000):
    x.append(i)
with open('bworst.csv','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        for i in row:
            y1.append(float(i))
with open('lbworst.csv','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        for i in row:
            y2.append(float(i))

plt.title('Min Max Time Complexity')
plt.plot(x,y1, label='Linear')
plt.plot(x,y2, label='Recursive Divide and Conquer')
plt.xlabel('Inputs')
plt.ylabel('Time Taken')
plt.legend()
plt.show()
