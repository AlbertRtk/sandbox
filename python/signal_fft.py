""" 
    Anaconda 3-2018.12
    Python 3.7
"""

import numpy as np
import matplotlib.pyplot as plt
from scipy.fftpack import fft

time_start = 0
time_end = 10
dt = 1/100

n = (time_end-time_start) / dt + 1
n = int(n)
time = np.linspace(0, n*dt, n)
freq = np.fft.fftfreq(n, dt)

f = 2  # Hz
omega = 2 * np.pi * f
signal = np.sin(omega*time) + np.random.rand(n)  # noisy signal
signal_fft = fft(signal)

# looking for max in freq spectrum (skipping const) and setting new signal
new_omega_ix = np.argmax(signal_fft[1:n//2])
new_omega = 2 * np.pi * freq[new_omega_ix]
new_signal = np.sin(new_omega*time)

# plotting
plt.subplot(311)
plt.plot(time, signal)
plt.subplot(312)
plt.plot(freq[0:n//2], signal_fft[0:n//2])
plt.subplot(313)
plt.plot(time, new_signal)

plt.show()

    