import re

normal_string = "Hello\nWorld"
print(normal_string)
print()

raw_string = r"Hello\nWorld"
print(raw_string)
print()

pattern = r"music"
test = "musicblablabla0123456789"
#test = "musi"

if re.match(pattern, test):
    print("Match")
else:
    print("No match")
print()

pattern = r"123"

print(re.match(pattern, "0"))
print(re.search(pattern, "1221232123123"))
print(re.findall(pattern, "1112223331221123321123123"))
print()

pattern = r"..."
found = re.search(pattern, "---.--..-...")
print(found)
print(found.group())
print(found.start())
print(found.end())
print(found.span())
print()

pattern = r"Kamil"
replacement = r"limaK"
text = "My name is Kamil. Hello Kamil. It is nice to meet you Kamil."

print(text)
print(re.sub(pattern, replacement, text))
for i in range(0, 5):
    print(re.sub(pattern, replacement, text, i))
print(text)
print()

#Metacharacters: .^$*+?{}[]()\|
#. -> any character except \n
#^ -> specifies the starting character or inverts character classes
#$ -> specifies the ending character
#* -> zero or more repetitions
#+ -> one or more repetitions
#? -> zero or one repetitions
#{} -> {x, y}, number of repetitions, from x to y repetitions, x is 0 by default, y is infinity by default
#[] -> character class, one of few
#() -> group of characters
#\-> as in \n
#| -> or

pattern = r".ight."

print(re.match(pattern, "might"))
print(re.match(pattern, "mighty"))
print(re.match(pattern, "fight"))
print(re.match(pattern, "\night\n"))
print()

pattern = r"^f..e$"

print(re.search(pattern, "onfire"))
print(re.search(pattern, "fate"))
print(re.search(pattern, "find"))
print(re.search(pattern, "site"))
print()

pattern = r"[ae][bc]"

print(re.search(pattern, "accuse"))
print(re.search(pattern, "february"))
print(re.search(pattern, "arc"))
print()

pattern = r"[C-V]: [0-9]"

print(re.search(pattern, "D: 5"))
print(re.search(pattern, "===L: 10==="))
print(re.search(pattern, "A: 100"))
print()

pattern = r"[^a-z]"

print(re.search(pattern, "imponderabilia"))
print(re.search(pattern, "blablabla blablabla"))
print(re.search(pattern, "aaaaaaaaaAaaaaaaaaa"))
print()

pattern = r"^[a-z]"

print(re.search(pattern, "po"))
print(re.search(pattern, "Tai Lung"))
print(re.search(pattern, "imponderabilia"))
print()

pattern = r"123([0-9])*456"

print(re.search(pattern, "0123456"))
print(re.search(pattern, "0001233344456"))
print(re.search(pattern, "123356"))
print()

pattern = r"123([0-9])+456"

print(re.search(pattern, "0123456"))
print(re.search(pattern, "0001233344456"))
print(re.search(pattern, "123356"))
print()

pattern = r"colou?r"

print(re.match(pattern, "color"))
print(re.match(pattern, "colour"))
print(re.match(pattern, "colouur"))
print()

pattern = r"(spam){3}$"

print(re.search(pattern, "blablabla spamspamspam"))
print(re.search(pattern, "bla spam"))
print(re.search(pattern, "spamspamspamspam"))
print()

pattern = r"Kung Fu Panda (1|2|3)"

print(re.search(pattern, "Kung Fu Panda 3"))
print(re.search(pattern, "---Kung Fu Panda 01230"))
print(re.search(pattern, "Kung Fu Panda 4"))
print()

pattern = r"ght$"

print(re.search(pattern, "fight"))
print(re.search(pattern, "fight$"))
print()

pattern = r"ght\$"

print(re.search(pattern, "fight"))
print(re.search(pattern, "fight$"))
print()

pattern = r"0(12(34)5)(67)(8(9))"
found = re.search(pattern, "===0123456789===")
print(found.groups())
print(found.group())
print(found.group(0))
print(found.group(1))
print(found.group(2))
print()

pattern = r"(.+) \1"

print(re.search(pattern, "abc abc"))
print(re.search(pattern, "abc xyz"))
print(re.search(pattern, "xyz xyz"))
print()

pattern = r"(.+) (.+) \2"

print(re.search(pattern, "abc xyz abc"))
print(re.search(pattern, "abc xyz xyz"))
print(re.search(pattern, "xyz abc abc"))
print()

#Special sequences:
#\1, \2, ... -> copy of the evaluated group number 1, 2, ...
#\d -> digit
#\D -> non-digit
#\s -> whitespace
#\S -> non-whitespace
#\w -> word character
#\W -> non-word character
#\A -> the string starts here, no characters before this anchor
#\Z -> the string ends here, no characters after this anchor
#/b -> at least 1 word to the left of \b and at least one word to the right of b, word boundary, Ctrl+Left/Rigth Arrow
