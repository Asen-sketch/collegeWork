import numpy as np
import matplotlib.pyplot as plt

# Генериране на синусоидален сигнал
t = np.linspace(0, 1, 1000, endpoint=False)  # времето от 0 до 1 секунда
A = 1  # амплитуда
f = 1  # честота
phi = 0  # фазов ъгъл

x = A * np.sin(2 * np.pi * f * t + phi)

# Начертаване на сигнала
plt.plot(t, x)
plt.title('Синусоидален сигнал')
plt.xlabel('Време (секунди)')
plt.ylabel('Амплитуда')
plt.grid(True)
plt.show()
