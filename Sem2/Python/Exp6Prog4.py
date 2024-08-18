f = open('E:\Academics\College Academics\Programming\Sem2\Python\TextFiles\InputFile.txt', 'r')
counter = 0
for i in f.read():
    if (i == " " or i == "," or i == "\n"):
        counter += 1
print(f"The number of words in the input file is : {counter + 1}")