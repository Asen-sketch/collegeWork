m = [
    [3, 5, 9, 12, 8, 7],
    [15, 22, 6, 3, 1, 4],
    [2, 3, 8, 7, 6, 5],
    [4, 2, 7, 10, 9, 8],
    [6, 5, 8, 11, 12, 14],
    [7, 8, 9, 10, 15, 22],
    [19, 18, 17, 16, 15, 14]
]

p = []

for elem in m[0]:
    p = p + [elem]

for i in range(1, len(m) - 1):
    p = p + [m[i][-1]]

for elem in m[-1][::-1]:
    p = p + [elem]

for i in range(len(m) - 2, 0, -1):
    p = p + [m[i][0]]

max_el = p[0]
for elem in p:
    if elem > max_el:
        max_el = elem

print(p)
print(max_el)

n = len(p)
for i in range(n - 1):
    for j in range(n - i - 1):
        if p[j] < p[j+1]:
            p[j], p[j+1] = p[j+1], p[j]

print("sort")
print(p)