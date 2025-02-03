# 2. Да се състави програма за обработка на двумерния масив A[N,N], където данните са
# цели числа в интервала [-10;10]. Програмата да извърши следните действия:
# ● отпечатване на условието на задачата;
# ● отпечатване на имената на автора на програмата;
# ● въвеждане на входните данни;
# ● отпечатване на входните данни;
# ● а) да се образува едномерен масив C, елементите на който са елементите от масива
# А, чиито квадрати са по-големи от 50
# ● б) полученият масив да се сортира по големина;
# ● отпечатване на получените резултати след обработката

def print_condition():
    print("\nЗадача: Обработка на двумерен масив A[N,N] с цели числа в интервала [-10;10].\n"
          "1. Да се образува едномерен масив C с елементите от A, чиито квадрати са > 50.\n"
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
                    if -10 <= element <= 10:
                        row.append(element)
                        break
                    else:
                        print("Моля, въведете число в интервала [-10, 10].")
                except ValueError:
                    print("Моля, въведете валидно цяло число.")
        matrix.append(row)
    return matrix

def print_matrix(matrix, name):
    print(f"\nМатрица {name}:")
    for row in matrix:
        print(" ".join(map(str, row)))

def extract_elements_with_large_squares(matrix):
    c = [element for row in matrix for element in row if element ** 2 > 50]
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

    c = extract_elements_with_large_squares(a)
    print(f"\nМасив C след извличане (елементи с квадрати > 50): {c}")

    c_sorted = sorted(c)
    print(f"\nМасив C след сортиране: {c_sorted}")

if __name__ == "__main__":
    main()