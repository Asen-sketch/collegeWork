import random

ls = []
while True:
    try:
        number = int(input("Enter number of elements (has to be between 25 and 34 including): "))
        if number >= 25 and number < 35:
            for x in range(number):
                ls.append(random.randint(-150, 150))
            break
    except ValueError:
        print("Invalid number.")
print(ls)

sumEven = 0
for x in range(2, len(ls), 2):
    sumEven += ls[x]
print("Sum of elements at even indices: ", sumEven)

count = 0
for x in ls:
    if x % 3 == 0 and not x % 5 == 0:
        count += 1
print("Count of elements divisible by 3, not multiples of 5: ", count)

product = 1
numbersExist = 0
for x in range(1, len(ls), 2):
    if ls[x] > 0:
        numbersExist = 1
        print(ls[x])
        product *= ls[x]
if numbersExist:
    print("Product: ", product)
else:
    print("Such numbers do not exist.")

ls.sort()
print(ls)
filtered_list = []
n = 3
for x in ls:
    if x < n:
        filtered_list.append(x)
print(filtered_list)

print('range', (max(ls)-min(ls)))

sublist = list(filter(lambda x: x % 2 == 0, filtered_list))
print(sublist)
countInSublist = len(sublist)
print('Count in sublist: ', countInSublist)

ls.remove(max(ls))
print(ls)

