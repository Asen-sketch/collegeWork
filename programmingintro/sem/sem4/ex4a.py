def calc():
    nums = []

    while True:
        try:
            num = float(input("Enter a number (0 for exit): "))
            if num == 0: break
            nums.append(num)
        except ValueError:
            print("Invalid number.")

    if nums:
        mult = 1
        for num in nums:
            mult *= num
        return mult
    else:
        return "List is empty."
    
print("The result of multiplication of entered numbers: ", calc())