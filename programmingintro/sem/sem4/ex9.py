def calculate_sum(numbers):
    return sum(numbers)

def calculate_even_sum(numbers):
    even_numbers = [num for num in numbers if num % 2 == 0]
    return sum(even_numbers)

numbers = tuple(map(int, input("Enter a sequence of integers separated by space: ").split()))

total_sum = calculate_sum(numbers)
print(f"Sum of all numbers: {total_sum}")

even_sum = calculate_even_sum(numbers)
print(f"Sum of even numbers: {even_sum}")