# • Напишете програма за обработка на матрица, която пази в едномерен масив:
# o сумата на елементите по главния диагонал
# o сумите на елементите по редове
# o броя елементи под главния диагонал, по-малки от сумите на индексите им

def process(arr):
    if not arr or not arr[0]:
        return 0
    
    n = len(arr)
    countbelow = 0

    sumdiag = sum(arr[i][i] for i in range(n))
    rowsum = [sum(row) for row in arr]

    for i in range(1, n):
        for j in range(i):
            if arr[i][j] < i + j:
                countbelow += 1

    result = [sumdiag] + rowsum + [countbelow]
    return result
    

matrix = [
    [2, 5, 7],
    [3, 6, 9],
    [4, 8, 10]
]

result = process(matrix) # [18, 14, 18, 22, 0]
print(result)