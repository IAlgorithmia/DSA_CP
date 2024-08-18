val = int(input("Enter the nuber of alphabets you want in a line : "))
f = open('MyFile.txt', 'w')
i = 65
while (i < 91):
    for j in range(val):
        if (i < 91):
            f.write(chr(i))
        else:
            break
        i += 1
    f.write('\n')