def toh(n, source, destination, auxillary):
    if (n > 0):
        toh(n-1, source, auxillary, destination)
        print(f"{n} is moved from {source} to {destination}")
        toh(n-1, auxillary, destination, source)
def toh_passintome(n, m):
    if (n < 1 or m < 3):
        print("Error")
        return
    toh(n, 1, m, 2)
toh_passintome(3, 3)
