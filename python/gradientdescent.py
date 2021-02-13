"""Linear regression with gradient descent"""

import numpy as np
import matplotlib.pyplot as plt


N = 100  # number of points
M = 3  # slope
C = 100  # intercept

r = 0.0002  # learning rate
i_max = 100_000  # max epochs

# generating linear dependent data with noise
X = np.arange(N)
noise = 100 * (np.random.rand(N)-0.5)
Y = M* X + C + noise

# model
m = 0
c = 0

for i in range(i_max):
    y_pred = m * X + c
    
    dm = X * (Y-y_pred)
    dm = (-1/N) * dm.sum()
    
    dc = (Y-y_pred)
    dc = -dc.sum() / N

    m = m - r * dm
    c = c - r * dc

    print(f'm = {m} \t c = {c}')

y_pred = m * X + c

# plotting results
plt.scatter(X, Y)
plt.plot(X, y_pred, 'r')
plt.show()
