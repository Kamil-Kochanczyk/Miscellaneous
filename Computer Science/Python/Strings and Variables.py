print("\"Hello world!\"")
print('\'Hello world!\'')
print()

print("'Hello world!'")
print('"Hello world!"')
print()

print("Hello world!\n")

print("""Hello
world
!""")
print()

print("Hello" + " " + "world" + '!' + '\n')

print("Hello world!" * 3)
print()

variable = 42
print(variable)
print(variable * 2)
print()

variable = "This is not a good practice"
print(variable)
print(variable * 2)
print()

#Assigning different data types to one variable is not a good practice

"""
This will be ignored by Python
This way you can write multiline comments
"""

"Will this be ignored?"

print("What is your name?")
name = input()
print("Hello " + name + "\n")

age = int(input("How old are you?\n"))
print("Your are", age, "years old\n")

text = "Python"
print(text)
text += " 3.8.10"
print(text)
text *= 3
print(text)
print()

print(walrus_operator := ":= (: - eyes, = - tusks)")
print(walrus_operator)
