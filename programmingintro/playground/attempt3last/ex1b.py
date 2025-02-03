ls = []

while True:
    try:
        n = int(input("Enter amount (15<n<35): "))
        if 15 < n < 35:
            for i in range(n):
                while True:
                    try:
                        num = int(input(f"Enter number {i+1} (30-300): "))
                        if 30 <= num <= 300:
                            ls.append(num)
                            break
                        else:
                            print("Invalid number")
                    except ValueError:
                        print("Invalid input.")
            break
        else:
            print("Invalid number.")
    except ValueError:
        print("Invalid input.")

ten_count = 0
for x in ls:
    if (x // 10) % 3 == 0:
        ten_count += 1

min_index = -1
min_value = float('inf')
for i, num in enumerate(ls):
    if num % 6 == 4 and num < min_value:
        min_value = num
        min_index = i

ls2 = [num for num in ls if 9 < num < 100 and (num % 2 == 0 or num % 3 == 0)]

odd_in = [num for i, num in enumerate(ls) if i % 2 != 0]
if odd_in:
    odd_avg = sum(odd_in) / len(odd_in)

ls.remove(min(num for num in ls if num % 2 == 0))