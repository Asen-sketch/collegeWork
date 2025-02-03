# Напишете програма за преобразуване на естествено число в двоично чрез
# рекурсивна функция.

def to_binary(n):
    if n < 2:
        return str(n)
    else:
        return to_binary(n // 2) + str(n % 2)

number = int(input("enter int: "))
binary_representation = to_binary(number)
print(f"binary of {number} is: {binary_representation}")
