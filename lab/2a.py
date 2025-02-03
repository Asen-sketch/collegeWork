# • Напишете програма, която изчислява сумата на елементите по обиколката на
# матрица.


def perimeter(arr):
    if not arr or not arr[0]:
        return 0
    
    rows = len(arr)
    cols = len(arr[0])
    per = 0

    per += sum(arr[0])
    per += sum(arr[rows - 1])

    for i in range (1, rows - 1):
        per += arr[i][0]
        per += arr[i][cols - 1]
    
    return per


matrix = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
    [13, 14, 15, 16]
]

result = perimeter(matrix) # trqbva da e 102
print(result)