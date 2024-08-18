fee = 10000
totalfee = 0
for i in range(10):
    fee = fee + (fee * 0.05)
print("The tuition fee in 10 years will be %.2f" % (fee))
for i in range(4):
    totalfee = totalfee + fee
    fee = fee + (fee * 0.05)
print("The total fee of 4 years' worth of tuition starting 10 years from now will be %.2f" % (totalfee))
