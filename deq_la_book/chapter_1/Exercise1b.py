import numpy as np
#draw the graph of e^t and y = e*t

t = np.linspace(-2,2,100)

y = (t)

z = y - np.log(t)

g = np.ones(t.shape)


from matplotlib import pyplot as plt 


plt.plot(t,z)

plt.plot(t,g)

plt.show()