ls = [54, 53, 57]
print(ls)
print(max(num for num in ls if num % 2 != 0))
ls.remove(max(num for num in ls if num % 2 != 0))
print(ls)