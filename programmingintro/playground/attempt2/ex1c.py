import random

ls = []

while True:
    try:
        n = int(input("Enter amount of elements [25, 35): "))
        if n >= 25 and n < 35:
            for x in range(n):
                ls.append(random.randint(-150, 150))
            break
    except ValueError:
        print("Invalid input.")

sumEven = 0
for x in range(2, len(ls), 2):
    sumEven += ls[x]

count = 0
for x in ls:
    if x % 3 == 0 and not x % 5 == 0:
        count += 1

product = 1
numbersExist = 0
for x in range (1, len(ls), 2):
    if ls[x] > 0:
        numbersExist = 1
        product *= ls[x]
if numbersExist:
    print("Product: ", product)
else:
    print('Numbers do not exist.')

ls.sort()
filtered_ls = [x for x in ls if x < n]

ls_range = max(ls) - min(ls)

filtered_subls = [x for x in filtered_ls if x % 2 == 0]

ls.remove(max(ls))
print(ls)