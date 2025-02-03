# 1. Да се състави програма за обработка на два масива A[N,N] и B[N,N], където данните са
# цели числа в интервала [-1000;1000]. Съответната програма да извършва следните
# действия:
# ● отпечатване на условието на задачата;
# ● отпечатване на автора на програмата;
# ● въвеждане на входните данни;
# ● отпечатване на входните данни;
# ● а) да се образува едномерен масив C[N], елементите на който да се образуват като
# сума от съответните елементи по главните диагонали на масивите А и В, б)получения
# масив да се сортира по големина;
# ● отпечатване на получените резултати след обработка а) и след обработка б)

def print_condition():
    print("\nЗадача: Да се обработят два масива A[N,N] и B[N,N].\n" 
          "1. Да се образува едномерен масив C[N], чиито елементи са сума от съответните елементи по главните диагонали на A и B.\n" 
          "2. Да се сортира масивът C по големина.\n")

def print_author():
    print("\nАвтор: Вашето име\n")

def input_matrix(n, name):
    print(f"\nВъведете елементите на матрицата {name} ({n}x{n}):")
    matrix = []
    for i in range(n):
        row = []
        for j in range(n):
            while True:
                try:
                    element = int(input(f"{name}[{i}][{j}]: "))
                    if -1000 <= element <= 1000:
                        row.append(element)
                        break
                    else:
                        print("Моля, въведете число в интервала [-1000, 1000].")
                except ValueError:
                    print("Моля, въведете валидно цяло число.")
        matrix.append(row)
    return matrix

def print_matrix(matrix, name):
    print(f"\nМатрица {name}:")
    for row in matrix:
        print(" ".join(map(str, row)))

def calculate_c(a, b, n):
    c = [a[i][i] + b[i][i] for i in range(n)]
    return c

def main():
    print_condition()
    print_author()

    while True:
        try:
            n = int(input("\nВъведете размер на матриците N (цяло число > 0): "))
            if n > 0:
                break
            else:
                print("Моля, въведете цяло число по-голямо от 0.")
        except ValueError:
            print("Моля, въведете валидно цяло число.")

    a = input_matrix(n, "A")
    b = input_matrix(n, "B")

    print_matrix(a, "A")
    print_matrix(b, "B")

    c = calculate_c(a, b, n)
    print(f"\nМасив C след изчисление (сумата по главните диагонали): {c}")

    c_sorted = sorted(c)
    print(f"\nМасив C след сортиране: {c_sorted}")

if __name__ == "__main__":
    main()