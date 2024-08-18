f1 = open('E:\Academics\College Academics\Programming\Sem2\Python\TextFiles\FirstFile.txt', 'r')
f2 = open('E:\Academics\College Academics\Programming\Sem2\Python\TextFiles\SecondFile.txt', 'r')
f3 = open('E:\Academics\College Academics\Programming\Sem2\Python\TextFiles\AnsFile.txt', 'w')
while True:
    line1 = f1.readline()
    line2 = f2.readline()
    if not (line1 and line2):
        break
    line1 = line1.strip() #To remove the newline character from its end
    line3 = line1 + " " + line2
    f3.write(line3)
f1.close()
f2.close()
f3.close()
f3 = open('E:\Academics\College Academics\Programming\Sem2\Python\TextFiles\AnsFile.txt', 'r')
print("The result is  :\n", f3.read())