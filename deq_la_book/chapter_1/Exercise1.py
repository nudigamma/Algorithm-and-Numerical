import numpy as np
#draw the graph of e^t and y = e*t

t = np.linspace(-2,2,100)

y = np.exp(t)

z = np.exp(1)*t


from matplotlib import pyplot as plt 

plt.plot(t,y)
plt.plot(t,z)

plt.show()