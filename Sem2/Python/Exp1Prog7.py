ti = int(input("Enter the initial temperature in degree celsius : "))
tf = int(input("Enter the final temperature in degree celsius : "))
m = int(input("Enter the mass of water in kilograms : "))
print("The energy requied is %.2f joules" % (m * (tf - ti) * 4184))
