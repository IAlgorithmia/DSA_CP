count = int(input("Enter how many packets of wheat you found : "))
for i in range(count):
    weight = int(input(f"Enter the weight of the package {i+1} : "))
    price = int(input(f"Enter the price of the package {i+1} : "))
    result = price/weight
    if (i == 0):
        ans = result
        val = i + 1
    else :
        if (result < ans):
            ans = result
            val = i + 1
print(f"The best deal is the package number {val} with price {ans : .2f} with unit weight")
            
    
