a = print("Keep entering the elements of the list. Enter EXIT to discontinue!")
elem = input("Enter the element : ")
nums = []
index = 0
while (elem != "EXIT"):
    elem = int(elem)
    nums[index] = elem
    index += 1
    elem = input("Enter the element : ")
length = 0
for i in nums:
    length += 1
for i in range(length):
    for j in range(i + 1, length):
        if (nums[i] < nums[j]):
            nums[j], nums[i] = nums[i], nums[j]
n = int(input("Enter n (nth largets value will be returned) : "))
print(f"The nth largest element of the list is {nums[n - 1]}")
