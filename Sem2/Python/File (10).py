set1 = {"paris", 100, "london", 1, "california", 5, "rishikesh", 3}
set2 = {"paris", 100, "california", 5, "newyork", 2, "Sydney", 2}
set3 = set1.intersection(set2)
print(set1.issuperset(set3))
print(set3.issubset(set1))
print(set1, set2, set3)