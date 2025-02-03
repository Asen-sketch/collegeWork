print("Да се състави програма за обработка на матрицата MAT[4,4].\n")
print("--- Автор: Иван Иванов ---\n")

# definition
MAT = [[0] * 4 for _ in range(4)]
print("Въведете елементите на матрицата ([0; 999]):")
for i in range(4):
    for j in range(4):
        while True:
            try:
                value = int(input(f"MAT[{i}][{j}] = "))
                if 0 <= value <= 999:
                    MAT[i][j] = value
                    break
                else:
                    print("между 0 и 999!")
            except ValueError:
                print("Въведете цяло число!")

# print entry
print("\n--- Въведената матрица ---")
for row in MAT:
    print(" ".join(map(str, row)))


# sortirane na stulb
def sum_of_digits(n):
    s = 0
    while n > 0:
        s += n % 10
        n //= 10
    return s

for col in range(4):
    column_elements = [(MAT[row][col], sum_of_digits(MAT[row][col])) for row in range(4)]
    column_elements.sort(key=lambda x: x[1])
    for row in range(4):
        MAT[row][col] = column_elements[row][0]

# print
print("\n--- Матрицата след сортиране на стълбовете по сумата от цифрите ---")
for row in MAT:
    print(" ".join(map(str, row)))
