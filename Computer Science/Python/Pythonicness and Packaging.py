import ms

def function(arg, *args, **kwargs):
    print(arg)
    print(args)
    print(kwargs)

function(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a="A", b="B", c="C")
print()

x, y, z = [1, 2, 3]
x, y = y, x
print(x)
print(y)
print(z)
print()

a, b, *leftovers, d = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
print(a)
print(b)
print(leftovers)
print(d)
print()

number = int(input("Enter an integer: "))
result = "Zero" if number == 0 else ("Negative" if number < 0 else "Positive")
print(result)
print()

ms.module_function()
print()
