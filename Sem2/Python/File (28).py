class Bank:
    bank_name = "BOI"
    ROI = 12.25
    @staticmethod
    def simple_interest(prin, n):
        SI = (prin * n * Bank.ROI)/100
        print(SI)
prin = float(input("Enter the principle amount : "))
n = float(input("Enter the number of years : "))
Bank.simple_interest(prin, n)