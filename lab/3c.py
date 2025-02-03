# Напишете програма за сумиране на елементите на едномерен масив чрез
# рекурсивна функция.

def recursive_sum(arr):
    if not arr:
        return 0
    else:
        return arr[0] + recursive_sum(arr[1:])

arr = [int(x) for x in input("enter array elements with spaces inbetween: ").split()]
result = recursive_sum(arr)
print(f"sum of elements: {result}")
