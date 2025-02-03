import random

while True:
    try:
        n = int(input("Enter number of elements in range [20, 30): "))
        if 20 < n < 30:
            break
        else:
            print("Error: Number must be an integer in range [20, 30).")
    except ValueError:
        print("Error: Please enter a valid integer.")

nums = [random.randint(-100, 100) for _ in range(n)]

sum_odd = sum(nums[1::2])
count_units_by_2 = sum(1 for num in nums if abs(num) % 10 == 0 and num != 0)
product_even_neg = 1
for num in nums:
    if num < 0 and num % 2 == 0:
        product_even_neg *= num

nums.sort(reverse=True)
second_list = [num for num in nums if num > n]
max_min_diff = max(nums) - min(nums)
odd_nums_second_list = [num for num in second_list if num % 2 != 0]
count_odd_nums_second_list = len(odd_nums_second_list)

min_val = min(nums)
nums.remove(min_val)

print("\nList:", nums)
print("Sum of odd indices:", sum_odd)
print("Count of units divisible by 2:", count_units_by_2)
print("Product of even negative:", product_even_neg)
print("Sorted list:", nums)
print("Second list (> n):", second_list)
print("Max-min difference:", max_min_diff)
print("Odd numbers from second list:", odd_nums_second_list)
print("Count of odd numbers from second list:", count_odd_nums_second_list)
print("List after removing min element:", nums)
