# 3. Да се състави програма за обработка на двумерния масив A[N,N], където данните са
# цели числа в интервала [-100;100]. Програмата да извърши следните действия:
# ● отпечатване на условието на задачата;
# ● отпечатване на имената на автора на програмата;
# ● въвеждане на входните данни;
# ● отпечатване на входните данни;
# ● а) да се образува едномерен масив C, елементите на който са елементите от масива
# А, попадащи в даден интервал [K - L] ;
# ● б) полученият масив да се сортира по големина;
# ● отпечатване на получените резултати след обработката

def print_condition():
    print("\nЗадача: Обработка на двумерен масив A[N,N] с цели числа в интервала [-100;100].\n"
          "1. Да се образува едномерен масив C с елементите от A, попадащи в зададен интервал [K - L].\n"
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
                    element = int(input(f"A[{i}][{j}]: "))
                    if -100 <= element <= 100:
                        row.append(element)
                        break
                    else:
                        print("Моля, въведете число в интервала [-100, 100].")
                except ValueError:
                    print("Моля, въведете валидно цяло число.")
        matrix.append(row)
    return matrix

def print_matrix(matrix, name):
    print(f"\nМатрица {name}:")
    for row in matrix:
        print(" ".join(map(str, row)))

def extract_elements_in_interval(matrix, k, l):
    c = [element for row in matrix for element in row if k <= element <= l]
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
            k = int(input("\nВъведете началото на интервала K: "))
            l = int(input("Въведете края на интервала L: "))
            if k <= l:
                break
            else:
                print("Началото на интервала K трябва да е по-малко или равно на края на интервала L.")
        except ValueError:
            print("Моля, въведете валидни цели числа.")

    c = extract_elements_in_interval(a, k, l)
    print(f"\nМасив C след извличане (елементи в интервала [{k}, {l}]): {c}")

    c_sorted = sorted(c)
    print(f"\nМасив C след сортиране: {c_sorted}")

if __name__ == "__main__":
    main()