# • Напишете програма за намиране на двойките елементи, симетрични на главния
# диагонал, в които горният елемент е по-малък от долния. В долната матрица
# симетричните елементи са оцветени по двойки.

def sympairs(arr):
    if not arr or not arr[0]:
        return 0
    
    n = len(arr)
    pairs = []

    for i in range(n):
        for j in range(i + 1, n):
            upper = arr[i][j]
            lower = arr[j][i]
            if upper < lower:
                pairs.append(((i, j), upper, (j, i), lower))

    return pairs


matrix = [
    [1, 5, 3],
    [4, 2, 6],
    [7, 8, 9]
]

result = sympairs(matrix) # 3 - 7, 6 - 8
for pair in result:
    print(f"symm elements: ({pair[0][0]}, {pair[0][1]}) = {pair[1]} and ({pair[2][0]}, {pair[2][1]}) = {pair[3]}")