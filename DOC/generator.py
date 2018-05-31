from math import exp
from math import sin
from math import cos
from math import sqrt
from math import pow
from math import tan
from math import log


def fun(x, y, z):
    return sin(x+y)+sin(z)+sin(x)


f = open("test.txt", "w")

#zakresy można zmienić
for i in range(-4,6):
    for j in range(-4,6):
        for k in range(-4,6):
            f.write(str(i) + '\t' + str(j) + '\t' + str(k) + '\t' + str(fun(i, j, k)) + '\n')

f.close()
