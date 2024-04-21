from scipy.misc import derivative #Derivative at a point
from scipy.integrate import quad #Definite integral over an interval
from math import e, pi, sin, cos

def f(x):
    return e**x;

print(derivative(f, 1))
print(derivative(f, 1, 1e-6))
print(derivative(f, 1, 1e-6, 2))
print()

def g(x):
    return x**2;

print(derivative(g, 10))
print(derivative(g, -8))
print()

h = lambda x: sin(x)

print(quad(h, 0, pi))
print()

i = lambda x: cos(x)

print(quad(i, 42, 69))
print()
