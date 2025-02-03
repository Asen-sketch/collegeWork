# Напишете програма за изчисление на x
# n
# (n - цяло число) чрез рекурсивна функция,

# съгласно следните формули:
# o n > 0: xn = x*xn-1
# o n = 0: x
# n = 1
# o n < 0: x
# n = 1/x-n

def power(x, n):
    if n > 0:
        return x * power(x, n - 1)
    elif n == 0:
        return 1
    elif n < 0:
        return 1 / power(x, -n)

x = float(input("enter x: "))
n = int(input("to the power of: "))
result = power(x, n)
print(f"result of {x}^{n} is: {result}")
