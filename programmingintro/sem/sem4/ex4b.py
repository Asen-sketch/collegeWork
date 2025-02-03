def calc(*args):
    if len(args) < 2:
        return "At least two numbers require to calculate multiplication between them."
    
    res = 1
    for arg in args:
        res *= arg
    
    return res

print("Multiplying 2, 3, 4:", calc(2, 3, 4))
print("Multiplying 5, 6, 7, 8:", calc(5, 6, 7, 8))
print("Multiplying 2, 3, 5, 10, 2:", calc(2, 3, 5, 10, 2))