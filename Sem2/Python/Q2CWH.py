import random
print("Welcome to the secret code game!\nYour choices are as follows : \n1. Encode a message\n2. Decode an encoded message\n3. Exit")
random_list = []
mode = 1
while (mode):
    choice = int(input("\nEnter your choice : "))
    match choice:
        case 1:
            message = input("Enter the secret message to be converted into secret code : ")
            if (len(message)<3):
                encoded = message[::-1]
            else:
                for i in range(6):
                    random_list.append(chr(random.randint(1, 123)))
                encoded = ""
                for i in range(3):
                    encoded += random_list[i]
                encoded += message[1:]
                encoded += message[0]
                for i in range(3):
                    encoded += (random_list[i+3])
            print("The encoded message is", encoded)
        case 2:
            message = input("Enter the secret message to be decoded : ")
            if (len(message)<3):
                decoded = message[::-1]
            else:
                decoded = ""
                decoded += message[len(message) - 4]
                decoded += message[3:len(message) - 4]
            print("The decoded message is", decoded)
        case 3:
            print("Hope to see you again!")
            mode = 0