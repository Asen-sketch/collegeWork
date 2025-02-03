def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i+1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr

# Обхожда масива, за да намери най-малкия елемент.
# Разменя го с първия елемент от несортираната част.
# Преминава към следващата несортирана част и повтаря, докато масивът се сортира.