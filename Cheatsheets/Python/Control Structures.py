true = True
false = False
print(true)
print(false)
print()

expression = (2 + 2 == 5)
print(expression)
expression = (2 + 2 != 5)
print(expression)
print()

print("10 == 10.0 -> " + str(10 == 10.0))
print("8 == 8.000000000000001 -> " + str(8 == 8.000000000000001))
print("8 == 8.0000000000000001 -> " + str(8 == 8.0000000000000001))
print("'Kamil' == \"Kamil\" -> " + str('Kamil' == "Kamil"))
print()

print("5 >= 5.0 -> " + str(5 >= 5.0))
print("k < K -> " + str('k' < 'K'))
print()

age = int(input("Enter your age: "))
money = int(input("Enter how much money you have: "))

if age >= 18:
    print("Come in")
elif money >= 520:
    print("Hmmm... all right")
else:
    print("Get out")

print()

number = int(input("Enter a random number: "))

if number != 0:
    if number > 0:
        print("Positive")
    else:
        print("Negative")
else:
    print("Zero")

print()

is_easy = input("Do you think that Python is easy? (y/n) ")
is_fun = input("Do you think that Python is fun? (y/n) ")

easy = (is_easy == 'y')
fun = (is_fun == 'y')

if (easy and fun):
    print("Python is easy and fun!")

if (easy or fun):
    print("Python is easy or fun!")

if (not easy) or (not fun):
    print("C'mon, you can do this, it'll be better later!")

print()

numbers = [ 10, 8, 5, 3, 1, 0, 69.42, "five hundred and twenty" ]
print(numbers)
print("My favourite number is: " + str(numbers[0]))
print("Love number is: " + numbers[-1])
print()

empty = []
print(empty)
print()

user_input = input("Enter a value that will fill your list: ")
user_list = [user_input, user_input, user_input]
print(user_list)
user_list[0] = "Haha"
print(user_list)
print(user_list + [3.141, 2.718, 1.618])
print(user_list * 3)
print()

list_2d = [ -1, 0, 1, [ "Haha", "Python" ]]
print(list_2d)
print(list_2d[3][1][0])
print("Haha" in list_2d)
print("Haha" in list_2d[3])
print("Python" not in list_2d)
print("Python" not in list_2d[3])
print()

word = "Time"
print(word)
print(word[0])
print()

#Strings are immutable lists

programming_languages = []
print(programming_languages)
print()

programming_languages.append("C#")
print(programming_languages)
programming_languages.append([ "C++", "C" ])
print(programming_languages)
programming_languages.append("Python")
print(programming_languages)
print()

print(len(programming_languages))
print(len(programming_languages[1]))
print(len(programming_languages[2]))
print()

programming_languages.insert(1, "JavaScript")
print(programming_languages)
programming_languages.insert(100, "C#")
print(programming_languages)
print()

index = programming_languages.index("C#")
print(index)
count = programming_languages.count("C#")
print(count)
programming_languages.remove("C#")
print(programming_languages)
programming_languages.reverse()
print(programming_languages)
print()

programming_languages.clear()
print(programming_languages)
programming_languages.append(-10)
programming_languages.append(-10.001)
programming_languages.append(-9.999)
print(programming_languages)
print(max(programming_languages))
print(min(programming_languages))
print()

i = 0
while i < 10:
    if (i == 7):
        i = i + 1
        continue
    print(i)
    i = i + 1

print()

i = 9
while i >= 0:
    print(i)
    i = i - 1
    if (i == 4):
        break

print()

apparently_random_words = [ "abcPdefYghiTjklHmnoOpqrNstuwxyz", "111I111555S555", "nufFnufUnufNnuf" ]

for word in apparently_random_words:
    for letter in word:
        if letter.isupper():
            print(letter, end = "")
    print(" ", end = "")

print("\n")

print(range(10))
print(list(range(10)))
print(range(1, 11))
print(list(range(1, 11)))
print(range(0, 11, 2))
print(list(range(0, 11, 2)))
print()

rows = int(input("Enter the number of rows: "))
print()

for i in range(rows):
    for j in range(i + 1):
        print("*", end = "")
    print()

print()
