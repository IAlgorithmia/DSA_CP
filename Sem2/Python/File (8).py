f = open("E:\Academics\College Academics\Codes\Sem2\Python\TextFiles\TextFile.txt", 'r')
number_of_words = 0
number_of_characters = 0
number_of_lines = 0
for line in f:
    number_of_lines += 1
    line = line.strip('\n')
    print(line)
    number_of_characters += len(line)
    print(number_of_characters)
    thelist = line.split()
    number_of_words += len(thelist)
f.close()
print("The number of words is : ", number_of_words)
print("The number of lines is : ", number_of_lines)
print("The number of characters is : ", number_of_characters)