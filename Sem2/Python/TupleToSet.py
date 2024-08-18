count = 0
tuple1 = (1, 2, 3, 4, 5, 6, 7, 12, 9.9, 0.123, -1223)
tuple2 = (12, 6 ,2 , "Vaibhav", "Jesus fkin christ")
min_length = min(len(tuple1), len(tuple2))
myset = set()
for i in range(min_length):
    myset.add(tuple1[i])
    myset.add(tuple2[i])
if (len(tuple1) > min_length):
    myset.update(tuple1[min_length:])
if (len(tuple2) > min_length):
    myset.update(tuple2[min_length:])
print(myset)