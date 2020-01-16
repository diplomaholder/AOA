import matplotlib.pyplot as plt
import csv

x = []
y1 = []
y2 = []
for i in range(5000,25001,500):
    x.append(i)
with open('iworst.csv','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        for i in row:
            y1.append(float(i))
with open('ibest.csv','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        for i in row:
            y2.append(float(i))

plt.subplot(2, 1, 1)
plt.title('Insertion Sort Time Complexity')
plt.plot(x,y1, label='Worst Case')
plt.legend()
plt.xlabel('Inputs')
plt.ylabel('Time Taken')
plt.subplot(2, 1, 2)
plt.plot(x,y2, label='Best Case')
plt.xlabel('Inputs')
plt.ylabel('Time Taken')
plt.legend()
plt.show()