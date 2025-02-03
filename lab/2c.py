# • Напишете програма, която сумира елементите по вторичния диагонал.

def secdiag(arr):
    if not arr or not arr[0]:
        return 0
    
    n = len(arr)

    sumsec = 0
    for i in range(n):
        sumsec += arr[i][n - 1 - i]
    
    return sumsec

matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

result = secdiag(matrix) # 15
print(result)