from random import randint

class Dragon:
    legs = 4
    
    def __init__(self, name, age, color):
        self.name = name
        self.age = age
        self.color = color

    def show_info(self):
        print("Name: " + self.name)
        print("Age: " + str(self.age))
        print("Color: " + self.color)

    def do_something(self, do = "Fly"):
        print(do)

toothless = Dragon("Toothless", 19, "Black")
toothless.show_info()
print()

toothless.do_something()
toothless.do_something("Roooaaarrrggghhh!")
print()

print(Dragon.legs)
print(toothless.legs)

Dragon.legs = 3
print(Dragon.legs)
print(toothless.legs)

toothless.legs = 5
print(Dragon.legs)
print(toothless.legs)

Dragon.legs = 4
toothless.legs = 4

print()

class Animal:
    def __init__(self, name):
        self.name = name

    def present(self):
        print("Name:")
        print("- " + self.name)

class Dog(Animal):
    def __init__(self, name, tricks = []):
        super().__init__(name)
        self.tricks = tricks

    def present(self):
        super().present()
        print("Tricks:")
        for trick in self.tricks:
            print("- " + trick)

jackson = Dog("Jackson", ["Following", "Fetching"])
jackson.tricks.append("Walking on two legs")
jackson.present()
print()

class Matrix:
    def __init__(self, rows, columns, random_values):
        assert (rows >= 0 and columns >= 0), "Matrix dimensions have to be positive"
        assert (round(rows) == rows and round(columns) == columns), "Matrix dimenstions have to be integers"
        self.rows = rows
        self.columns = columns
        self.content = []
        for i in range(rows):
            self.content.append([])
            for j in range(columns):
                if random_values:
                    self.content[i].append(randint(-3, 3))
                else:
                    self.content[i].append(0)

    def __mul__(self, other):
        assert self.columns == other.rows, "Matrix dimenstions are incorrect"
        result = Matrix(self.rows, other.columns, False)
        important_number = self.columns
        for i in range(result.rows):
            for j in range(result.columns):
                for k in range(important_number):
                    result.content[i][j] += self.content[i][k] * other.content[k][j]
        return result

    def show(self):
        for i in range(self.rows):
            for j in range(self.columns):
                print(str(self.content[i][j]) + "; ", end = "")
            print()

A = Matrix(2, 3, True)
B = Matrix(3, 4, True)
C = A * B

print("A:")
A.show()
print()

print("B:")
B.show()
print()

print("C:")
C.show()
print()

print()

class Useless:
    def __init__(self, value):
        self._value = value
        self.__another = value * (-1)

useless = Useless(10)
print("Single underscore signifies a weakly private attribute/method")
print("Weakly private things won't be imported from modules")
print("Use them at your own risk")
print(useless._value)
print()

print("Double underscore signifies a strongly private attribute/method")
print("Such things cannot be directly accessed from outside of class")
print(useless._Useless__another)
print()

class Rectangle:
    def __init__(self, l, w):
        self.l = l
        self.w = w
        self._sides = 2

    def get_area(self):
        return self.l * self.w

    @classmethod
    def square(cls, a):
        return cls(a, a)

    @staticmethod
    def validate(rectangle):
        return rectangle.l >= 0 and rectangle.w >= 0

    @property
    def sides(self):
        return self._sides

    @sides.setter
    def sides(self, value):
        if value >= 1.5 and value < 2.5:
            self._sides = value
        else:
            raise ValueError("It should be possible to round the number to 2")

r = Rectangle(8, 10)
print(r.get_area())
print(Rectangle.validate(r))
print(r.sides)
r.sides = 1.75
print(r.sides)
print()

#s = r.square(3)
s = Rectangle.square(-5)
print(s.get_area())
print(Rectangle.validate(s))
print(s.sides)
s.sides = 2.49
print(s.sides)
print()
