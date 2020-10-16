import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm

x = np.loadtxt('/Users/germanzvezdin/Desktop/Git/SUPREMUM/cmake-build-debug/x.txt')
y = np.loadtxt('/Users/germanzvezdin/Desktop/Git/SUPREMUM/cmake-build-debug/y.txt')
z = np.loadtxt('/Users/germanzvezdin/Desktop/Git/SUPREMUM/cmake-build-debug/z.txt')

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(x,y,z,cmap=cm.coolwarm)
ax.set_xlabel('x')
ax.set_ylabel('y')
plt.title(r'$u(x,y)$')
plt.savefig('ans.png')
plt.show()
