# Напишете програма за проверка за наличие на цифра в естествено число чрез
# рекурсивна функция.

def contains_digit(number, digit):
    if number == 0:
        return False
    elif number % 10 == digit:
        return True
    else:
        return contains_digit(number // 10, digit)

number = int(input("enter int: "))
digit = int(input("enter digit to search: "))
result = contains_digit(number, digit)
if result:
    print(f"digit {digit} is found in {number}.")
else:
    print(f"digit {digit} is not in {number}.")
