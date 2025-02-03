def set_gen(nums):
    res = set()

    for num in nums:
        res.add(str(num))

        for repeat in range(2, num + 1):
            res.add(str(num) * repeat)
    
    return res

numbers = [4, 2, 3]
result = set_gen(numbers)
print(result)