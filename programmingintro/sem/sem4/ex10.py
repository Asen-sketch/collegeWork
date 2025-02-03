def f1(x):
    binary_list = []
    binary_string = ""

    while x > 0:
        remainder = x % 2
        binary_list.insert(0, remainder)
        binary_string += str(remainder)
        x //= 2

    print(f"The number from decimal to binary is: {binary_string}")

    answer = input("Do you wish for a check 2->10? (Y/N): ")

    if answer.upper() == 'Y':
        f2(binary_string)
    elif answer.upper() == 'N':
        print("The converted number unchecked is:", binary_string)
    else:
        print("Invalid input, skipping check.")
        print("The converted number unchecked is:", binary_string)

def f2(binary_string):
    decimal_result = int(binary_string, 2)
    print("Result from check 2->10 is:", decimal_result)

input_number = int(input("Enter a positive integer: "))
f1(input_number)
