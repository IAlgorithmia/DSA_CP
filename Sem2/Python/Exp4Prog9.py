amount = int(input("Enter the loan amount : $"))
years = int(input("Enter the number of years : "))
rate = int(input("Enter the interest rate : "))
balance = amount
monthly_principal = amount / (12*years)
print("The total number of payments is : {}".format(12*years))
print("S.No. \t Monthly Payment \t Monthly Interest \t \t Balance")
for i in range(12*years):
    monthly_interest = (balance * (rate / 100))
    monthly_payment = monthly_principal + monthly_interest
    balance -= monthly_principal
    print(" {} \t   {:.2f} \t\t   {:.2f} \t\t\t {:.2f}".format(i + 1, monthly_payment, monthly_interest, balance))
