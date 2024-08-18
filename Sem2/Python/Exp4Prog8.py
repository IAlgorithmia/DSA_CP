value = float(input("Enter the amount : $"))
years = int(input("Enter the time period in years : "))
print("Interest Rate\tMonthly payments\tTotal Payment")
rate = 5
while (rate <= 8):
    total = value*(rate/100)*years
    rate += 0.125
    monthly = total / (12*years)
    print("   {:.2f} \t    {:.2f} \t \t   {:.2f}".format(rate, monthly, total))
