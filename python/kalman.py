"""
Based on:
https://forbot.pl/blog/filtr-kalmana-w-praktyce-3-przyklady-z-kodami-id7342
"""
import numpy as np
import matplotlib.pyplot as plt


duration = 10
dt = 0.01        # time step
a = 0.4         # acceleration

ds = 0.5    # GPS accurancy
da = 0.1    # acceleration noise

x = np.array([[0], [0]])   # state vector
x_hat = x.copy()

A = np.array([[1, dt],[0, 1]])
B = np.array([[0.5*dt*dt], [dt]])
H = np.array([[1, 0]])
R = ds * ds

s = (0.5*dt*dt) * da
v = dt * da
Q = np.array([[s, v]])
Q = Q * Q.T
P = Q.copy()

pos = []
posmeas = []
poshat = []

timestamps = np.arange(0, duration+dt, dt)

for t in timestamps:
    x = A.dot(x) + B * a \
        + da * np.array([[np.random.randn()*0.5*dt*dt], [np.random.randn()*dt]])
    z = H.dot(x) + ds * np.random.randn()
    x_hat = A.dot(x_hat) + B * a
    P = A.dot(P).dot(A.T) + Q
    K = P.dot(H.T) * np.linalg.inv(H.dot(P).dot(H.T)+R)
    x_hat = x_hat + K.dot((z-H.dot(x_hat)))
    P = (np.identity(2)-K).dot(P)

    pos.append(x[0][0])
    posmeas.append(z[0][0])
    poshat.append(x_hat[0][0])

tx = list(timestamps)
plt.plot(tx, pos, 'b', tx, posmeas, 'r', tx, poshat, 'g')
plt.show()
