def char_histogram(txt):
    res = {}

    for char in txt:
        if char in res:
            res[char] += 1
        else:
            res[char] = 1

    return res

example = 'This is an example'
print(example)
print(char_histogram(example))