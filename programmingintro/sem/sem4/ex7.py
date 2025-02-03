import random

y = 0
k = 0

def f1(x):
    if x == 0:
        y = f2(x)
    else:
        y = 4*x
    return y

def f2(x):
    x = random.randint(1, 10)
    k = f1(x)
    return k

print("entering number 5")
k = f1(5)
print(k)


print("entering number 0")
k = f1(0)
print(k)
