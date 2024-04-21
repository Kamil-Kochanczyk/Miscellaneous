import math
from random import randint
from math import e as exponential, sin as sine, cos as cosine

def say_hello():
    print("Hello!")

def say_hello_to(name):
    print("Hello " + name + "!")

# Available operations: +, -, *, /
def calculate(x, y, operation):
    """
This is a docstring
Will it be visible?
Hopefully yes
    """
    result = None
    if (operation == "+"):
        result = x + y
    elif (operation == "-"):
        result = x - y
    elif (operation == "*"):
        result = x * y
    elif (operation == "/"):
        result = x / y
    else:
        print("Invalid operation")
    return result

def add(x, y):
    return x + y

def subtract(x, y):
    return x - y

def multiply(x, y):
    return x * y

def divide(x, y):
    return x / y

def print_operation(operation, x, y):
    print(operation(x, y))

say_hello()
say_hello_to("Kamil")
print()

x = 10.0
y = 8.0

print(calculate(x, y, "+"))
print(calculate(x, y, "-"))
print(calculate(x, y, "*"))
print(calculate(x, y, "/"))
print(calculate(x, y, "^"))
print()

print(calculate.__doc__)
print()

operations = [add, subtract, multiply, divide]

for operation in operations:
    print_operation(operation, x, y)
print()

print(math.pi)
print(randint(1, 5))
print(sine(exponential))
print(cosine(exponential))
