price1, weight1, price2, weight2 = input("Enter the price and weight of both the packages : ").split()
price1 = int(price1)
price2 = int(price2)
weight1 = int(weight1)
weight2 = int(weight2)
rate1 = weight1/price1
rate2 = weight2/price2
if (rate1 > rate2):
    print("The first package is better!")
elif (rate1 < rate2):
    print("The second package is better!")
else:
    print("Both packages are eqally costly")
