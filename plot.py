import matplotlib.pyplot as plt
import csv

x = []
y1 = []
y2 = []
for i in range(100,1001,10):
    x.append(i)
with open('kworst.csv','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        for i in row:
            y1.append(float(i))

plt.title('Kruskal Time Complexity')
plt.plot(x,y1, label='Kruskal')
plt.xlabel('Inputs')
plt.ylabel('Time Taken')
plt.legend()
plt.show()
