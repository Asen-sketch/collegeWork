# 4. Да се състави програма за обработка на двумерния масив A[N,N], където данните са
# реални числа в интервала [-1000;1000]. Програмата да извърши следните действия:
# ● отпечатване на условието на задачата;
# ● отпечатване на имената на автора на програмата;
# ● въвеждане на входните данни;
# ● отпечатване на входните данни;
# ● а) да се образува едномерен масив C, елементите на който са елементите от масива
# А, намиращи се извън даден интервал [L;M];
# ● б) полученият масив да се сортира по големина;
# ● отпечатване на получените резултати след обработката

def print_condition():
    print("\nЗадача: Обработка на двумерен масив A[N,N] с реални числа в интервала [-1000;1000].\n"
          "1. Да се образува едномерен масив C с елементите от A, намиращи се извън даден интервал [L;M].\n"
          "2. Да се сортира масивът C по големина.\n")

def print_author():
    print("\nАвтор: Вашето име\n")

def input_matrix(n):
    print(f"\nВъведете елементите на матрицата A ({n}x{n}):")
    matrix = []
    for i in range(n):
        row = []
        for j in range(n):
            while True:
                try:
                    element = float(input(f"A[{i}][{j}]: "))
                    if -1000 <= element <= 1000:
                        row.append(element)
                        break
                    else:
                        print("Моля, въведете число в интервала [-1000, 1000].")
                except ValueError:
                    print("Моля, въведете валидно реално число.")
        matrix.append(row)
    return matrix

def print_matrix(matrix, name):
    print(f"\nМатрица {name}:")
    for row in matrix:
        print(" ".join(map(lambda x: f"{x:.2f}", row)))

def extract_elements_outside_interval(matrix, l, m):
    c = [element for row in matrix for element in row if element < l or element > m]
    return c

def main():
    print_condition()
    print_author()

    while True:
        try:
            n = int(input("\nВъведете размер на матрицата N (цяло число > 0): "))
            if n > 0:
                break
            else:
                print("Моля, въведете цяло число по-голямо от 0.")
        except ValueError:
            print("Моля, въведете валидно цяло число.")

    a = input_matrix(n)
    print_matrix(a, "A")

    while True:
        try:
            l = float(input("\nВъведете началото на интервала L: "))
            m = float(input("Въведете края на интервала M: "))
            if l <= m:
                break
            else:
                print("Началото на интервала L трябва да е по-малко или равно на края на интервала M.")
        except ValueError:
            print("Моля, въведете валидни реални числа.")

    c = extract_elements_outside_interval(a, l, m)
    print(f"\nМасив C след извличане (елементи извън интервала [{l}, {m}]): {['%.2f' % elem for elem in c]}")

    c_sorted = sorted(c)
    print(f"\nМасив C след сортиране: {['%.2f' % elem for elem in c_sorted]}")

if __name__ == "__main__":
    main()

    
