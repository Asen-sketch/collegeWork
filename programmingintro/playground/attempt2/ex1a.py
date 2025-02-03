import random

ls = []

#Paragraph 1
while True:
    try:
        n = int(input("Enter the amount of elements (20<n<30): "))
        if n > 20 and n < 30:
            for x in range(n):
                ls.append(random.randint(-100, 100))
            break
        else:
            print("Invalid number.")
    except ValueError:
        print("Invalid input.")

sumOdd = 0
for x in range(1, len(ls), 2):
    sumOdd += ls[x]

div_by_two = sum(1 for num in ls if abs(num) % 10 == 0 and num != 0)

prod_even_neg = 1
for num in ls:
    if num < 0 and num % 2 == 0:
        prod_even_neg *= num

ls.sort(reverse=True)
print(ls)


# Paragraph 2
filt_ls = []

for num in ls:
    if num > n:
        filt_ls.append(num)

minmax = max(filt_ls) - min(filt_ls)

filtodds = [num for num in ls if num % 2 != 0]
print(filtodds)
print(len(filtodds))

filt_ls.remove(min(filt_ls))
