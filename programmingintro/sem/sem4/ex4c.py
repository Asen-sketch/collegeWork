def calc(nums):
    res = 1
    for num in nums:
        res *= num
    return res

def funct(nums=(2, 3, 4)):
    return 0.5 * calc(nums)

print("Multiplying 2, 3, 4 and halving:", funct((2, 3, 4)))
print("Multiplying 5, 6, 7, 8 and halving:", funct((5, 6, 7, 8)))
print("Multiplying 2, 3, 5, 10, 2 and halving:", funct((2, 3, 5, 10, 2)))