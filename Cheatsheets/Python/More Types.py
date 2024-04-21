print("")
print(None)
print()

def return_none():
    print("Return None")

value = return_none()
print(value)
print()

dictionary = { "Key 1": 10, "Key 2": 20, "Key 3": 30 }

for key in dictionary:
    print(key + ": " + str(dictionary[key]))
print()

print("Key 1" not in dictionary)
print(10 in dictionary)
print()

print(dictionary.get("Key 1"))
print(dictionary.get("Key 0"))
print(dictionary.get("Key -1", "Invalid key"))
print()

some_tuple = (0, '0', "Zero")
print(some_tuple)
print(some_tuple[0])
print()

zero_int, zero_char, zero_string = some_tuple
print(zero_int)
print(zero_char)
print(zero_string)
print()

favourite_numbers = [ 10, 8, 5, 3, 1, 0, -1, 520, 69, 42 ]
print(favourite_numbers)
print(favourite_numbers[4:7])
print(favourite_numbers[:7])
print(favourite_numbers[7:])
print(favourite_numbers[::])
print(favourite_numbers[::-1])
print(favourite_numbers[7:4:-1])
print(favourite_numbers[0:100:2])
print()

cubes = [i**3 for i in range(10)]
print(cubes)
cubes = [i**3 for i in range(10) if i**3 % 2 == 0]
print(cubes)
print()

print("My truly favourite numbers are: {0}, {1} and {2}".format(10, 42, 69))
print("I hate numbers: {x}, {y} and {z}".format(x = 7, y = 11, z = 13))
x = -1
y = 0
z = 1
print(f"Arguably most important constats in math are: {x}, {y} and {z}")
print()

sentence = "Chasing-After-The-Wind"
split_sentence = sentence.split("-")
print(split_sentence)
join_sentence = " ".join(split_sentence)
print(join_sentence)
print()

print(sum([abs(-10), round(10.9876543210, 2)]))
print()

if all([i > 0 for i in favourite_numbers]):
    print("All of my favourite numbers are positive")
else:
    print("Not all of my favourite numbers are positive")
print()

if any([i == -1 for i in favourite_numbers]):
    print("There is -1 among my favourite numbers")
else:
    print("There is no -1 among my favourite numbers")
print()

for pair in enumerate(favourite_numbers):
    print(pair)
print()
