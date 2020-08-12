#This short script creates figure 1.1 in Gilbert strang book
import numpy as np
from matplotlib import pyplot as plt 

figure_1_1_caption = "Growth, Faster growth, and decay. The solutions are e^t e^2t and e^-t"

x = np.linspace(-1,1,40)
exp_t = np.exp(x)
exp_2t = np.exp(2*x)
exp_minust = np.exp(-x)

plt.figure() 
plt.plot(x,exp_t)

plt.plot(x,exp_2t)
plt.plot(x,exp_minust)
plt.show()