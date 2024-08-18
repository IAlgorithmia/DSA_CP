f1 = open('E:\Academics\College Academics\Programming\Sem2\Python\TextFiles\CopyFromMe.txt', 'r')
f2 = open('E:\Academics\College Academics\Programming\Sem2\Python\TextFiles\PasteIntoMe.txt', 'w')
list1 = f1.readlines()
f2.writelines(list1)
'''
OR WE CAN DO : 
for line in list1:
    f2.write(line)'''
f1.close()
f2.close()