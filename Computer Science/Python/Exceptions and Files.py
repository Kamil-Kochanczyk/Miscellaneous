try:
    x = int(input("Enter x: "))
    y = int(input("Enter y: "))
    print(x / y)
except ZeroDivisionError:
    print("Dividing by 0 is unefined :(")
except (ValueError, TypeError):
    print("Problem with input value/type :(")
except:
    print("Unknown error :(")
    raise NameError("Unknown variable name")
finally:
    print("This code will run no matter what")

print()

def kelvin_to_celsius(kelvin):
    assert (kelvin >= 0), "Temperature cannot be less than the absolute zero"
    return kelvin - 273.15

celsius = kelvin_to_celsius(10)
print(celsius)
print()

path = "/home/kamil/Desktop/Testfile.txt"

file = open(path, "w")
for i in range(10):
    file.write("Line " + str(i) + "\n")
file.close()

file = open(path, "r")

content = file.read()
print(content)

file.seek(0)

print(file.read(3))
print(file.read(5))
print(file.read())
print(file.read())

file.seek(0)

lines = file.readlines()
for i in range(len(lines)):
    print(lines[i], end="")
print()

file.close()

file = open(path, "w")
bytes_written = file.write("File has been overwritten\n")
print(bytes_written)
print()

file.close()

file = open(path, "r")
content = file.read()
print(content)
file.close()

inexistent = "inexistent"
try:
    inexistent_file = open(inexistent)
    try:
        print(inexistent_file.read())
    except:
        print("Problem with reading the file")
    finally:
        inexistent_file.close()
except:
    print("Problem with opening the file")

print()

with open(path) as f:
    print(f.read())
    print("File is a local variable here")
    print("It will be automatically closed at the end of the block")
