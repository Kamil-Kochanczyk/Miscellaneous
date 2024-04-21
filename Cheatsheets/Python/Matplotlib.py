import matplotlib.pyplot as plt
import numpy as np

x = [-2, -1, 0, 1, 2]
y = [4, 1, 0, 1, 4]

plt.plot(x, y)

plt.xlabel("Arguments")
plt.ylabel("Values")
plt.title("Test graph")
plt.show()

x1 = x.copy()
y1 = [-2, -1, 0, 1, 2]

plt.plot(x1, y1, label="y = x", color="green", linestyle="dotted", linewidth=6)

x2 = x.copy()
y2 = [-6, -3, 0, 3, 6]

plt.plot(x2, y2, label="y = 3x", marker="o", markerfacecolor="red", markersize=12)

plt.xlim(-3, 3)
plt.ylim(-10, 10)

plt.xlabel("x")
plt.ylabel("y")
plt.title("Linear functions")
plt.legend()
plt.show()

xc = np.arange(-2 * (np.pi), 2 * (np.pi), 0.1)
yc = np.cos(xc)

plt.plot(xc, yc)

plt.xlabel("x")
plt.ylabel("cos(x)")
plt.title("Cosine")
plt.show()
