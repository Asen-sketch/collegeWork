ls = []

while True:
    try:
        n = int(input("Enter amount (10<n<40): "))
        if 10 < n < 40:
            for i in range(n):
                while True:
                    try:
                        num = int(input(f"Enter number {i+1}: "))
                        if 50 <= num <= 500:
                            ls.append(num)
                            break
                        else:
                            print("Invalid num.")
                    except ValueError:
                        print("Invalid input.")
            break
        else:
            print("Invalid number.")
    except ValueError:
        print("Invalid input.")

tencount = 0
for i in ls:
    if i // 10 % 4 == 0:
        tencount += 1

max_index = -1
max_value = float('-inf')
for i , num in enumerate(ls):
    if num % 7 == 3 and num > max_value:
        max_value = num
        max_index = i
    else:
        print("no such numbers")

ls2 = [num for num in ls if num if 99 < num < 1000 and (num % 5 == 0 or num % 7 == 0)]

odd_ls = [num for i, num in enumerate(ls) if i % 2 != 0]
avg = 0
if odd_ls:
    avg = sum(odd_ls) / len(odd_ls)

ls.remove(max(num for num in ls if num % 2 != 0))