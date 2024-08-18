# 65 to 90 - Capital Letters
# 97 to 122 - Small Letters
# 48 to 57 - Numbers
text = ""
while True:
    line = input("Enter the line or simply press enter to stop the input : ")
    if (len(line) != 0):
        if (text == ""):
            text = text + line
        else:
            text = text + "\n" + line
    else:
        break
acount = 0
dcount = 0
scount = 0
newlinecount = 0
for i in text:
    if ((ord(i) < 91 and ord(i) > 64) or (ord(i) < 123 and ord(i) > 96)):
        acount += 1
    elif ((ord(i) < 58 and ord(i) > 47)):
        dcount += 1
    elif (i == " "):
        scount += 1
    elif (i == "\n"):
        newlinecount += 1
print("The number of characters in the text is ", len(text) - newlinecount)
print("The number of alphabets in the text is", acount)    
print("The number of digits in the text is", dcount)    
print("The number of spaces in the text is", scount)    
print("The number of words in the text is", len(text) - acount - dcount + 1)    
        