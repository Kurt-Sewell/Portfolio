import math
import numpy as np


def function():
    x = np.linspace(0.1, 0.25, 10)
    y = []

    for i in x:
        y.append((6*(i**3) - (3*i) - 4) / (8 * math.sin(5*i)))
    return y


def payment(P, years, APR):
    i = APR / (12 * 100)
    A = P * ((i*(1+i)**(years*12))/((1+i)**(years*12)-1))
    return A


def sine_series(x, n):
    neg = 1
    sine = 0
    for i in range(n):
        print("i = ", i)
        sine += neg*(x**((2*i)+1)/(math.factorial(2*i+1)))
        neg *= -1
        print(sine)
    err = (abs((math.sin(x) - sine))/math.sin(x))*100

    return sine, err


def arctan4(y, x):
    r = math.sqrt(x**2+y**2)
    if (x > 0):
        theta = math.atan(y/x)
    elif (x < 0):
        if (y > 0):
            theta = math.atan(y/x)+math.pi
        elif (y < 0):
            theta = math.atan(y/x)-math.pi
        else:
            theta = math.pi
    else:
        if (y > 0):
            theta = math.pi/2
        elif (y < 0):
            theta = -math.pi/2
        else:
            theta = 0
    return r, theta


print(arctan4(0, 2))
