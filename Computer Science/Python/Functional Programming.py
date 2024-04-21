from math import sin, cos, pi, e
from functools import reduce

def composition(outer, inner, arg):
    return outer(inner(arg))

print("sin(cos(pi)) = " + str(composition(sin, cos, pi)))
print()

print((lambda x, y: x**2 + y**2)(8, 10))
print()

numbers = [10, 8, 42, 69, 520, 1, 0, -1, 3, 5]
print(numbers)
print()

opposites = list(map((lambda x: x * (-1)), numbers))
print(opposites)
print()

inverts = ["1/" + str(x) for x in numbers]
print(inverts)

inverts = list(filter((lambda x: not x.endswith("/0")), inverts))
print(inverts)

inverts = [x.split("/") for x in inverts]
inverts = [int(x[0]) / int(x[1]) for x in inverts]
inverts = [round(x, 2) for x in inverts]
print(inverts)
print()

lists = [numbers, opposites, inverts]

for l in lists:
    maximum = reduce((lambda x, y: x if x > y else y), l)
    print(maximum)
print()

def generator(n):
    for i in range(n + 1):
        print("Yielding " + str(i) + "...")
        yield i
        print("Yielded " + str(i))
        print()

for i in generator(5):
    print(i)
print()

def destroy_word(word):
    new = word
    while len(new) > 0:
        yield new
        new = new.replace(str(new[0]), '', 1)
    print("Word destroyed!")

for word in destroy_word("Python"):
    print(word)
print()

print(list(destroy_word("Kamil Kochańczyk")))
print()

def append_second(function):
    def append(result):
        function(result)
        print("s", end = "")
    return append

def highlight_result(function):
    def highlight(result):
        print("=" * 10)
        function(result)
        print()
        print("=" * 10)
    return highlight

def print_result(result):
    print("Result: " + str(result), end = "")

@highlight_result
@append_second
def combined(result):
    print_result(result)

print_result(5)
print()
print()

print_in_seconds = append_second(print_result)
print_in_seconds(5)
print()
print()

print_highlighted = highlight_result(print_result)
print_highlighted(5)
print()

combined(5)
print()

def gcd(x, y):
    assert (round(x) == x and round(y) == y), "x and y should be integers"
    if x % y == 0:
        return abs(y)
    else:
        return abs(gcd(y, x % y))

print(gcd(-78, -282))
print()

empty_set = set()
print(empty_set)
print()

N = { 2, 1, 0, 1, 2 }
print(N)
print()

M = set(numbers)
print(M)
print()

popped = M.pop()
M.add(100)
M.remove(10)
print(popped)
print(M)
print()

A = { 0, 1, 2, 3, 4 }
B = { 3, 4, 5, 6, 7 }
print(A | B)
print(A & B)
print(A - B)
print(B - A)
print(A ^ B)
print()
