f = open('E:\Academics\College Academics\Programming\Sem2\Python\TextFiles\Marks.txt', 'r')
i = 0
while True:
    i += 1
    line = f.readline()
    if not line:
        break
    list = line.split(',')
    m1 = list[0]
    m2 = list[1]
    m3 = list[2]
    print(f"The marks of student {i} in Math :", m1)
    print(f"The marks of student {i} in Chemistry :", m2)
    print(f"The marks of student {i} in Physics :", m3)
    #Note that the type of m1, m2 and m3 is string