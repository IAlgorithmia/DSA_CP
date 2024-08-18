hxchar = input("Enter the hex character : ")
m = 0
num = 0
for i in range(len(hxchar) - 1, -1, -1):
    if (hxchar[i].isdigit()):
        num = num + (int(hxchar[i]))*(16**m)
        m = m + 1
    else:
        match hxchar[i]:
            case 'A':
                num = num + ((10)*(16**m))
            
            case 'B':
                num = num + ((11)*(16**m))
            
            case 'C':
                num = num + ((12)*(16**m))
            
            case 'D':
                num = num + ((13)*(16**m))
            
            case 'E':
                num = num + ((14)*(16**m))
            
            case 'F':
                num = num + ((15)*(16**m))
        m = m + 1
print("The number in decimal is : ", num)
