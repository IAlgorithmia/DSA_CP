f = open("E:\Academics\College Academics\Programming\Sem2\Python\TextFiles\TextFile.txt", "r")
thelist = []
while True:
    line = f.readline()
    if not line:
        break
    print(f"The line is : {line}")
    thelist.append(line)
print(f"\n\nThe entire file in a list is : {thelist}\n\n")
f.close()