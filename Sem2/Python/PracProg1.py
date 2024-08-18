string, char = input("Enter the string : "), input("Enter the character : ")
count = 0
for i in string:
    if (i == char):
        count += 1
print(f"The character {char} occurs {count} times in the string")
