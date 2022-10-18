import numpy as np

x = 1
y = np.(sin(pi*x)/x)

print (y)
yprime = y.diff(x)
print(yprime)
