from collections import Counter
import random

def count_it(range_, length):

    sequence = [random.randint(*range_) for _ in range(length)]
    counter = Counter(sequence)
    commons = counter.most_common(3)
    result = dict(commons)

    return result, sequence


range_ = (0, 9)
length = 20

result, sequence = count_it(range_, length)
print("Random sequence:", sequence)
print("Three most common numbers:", result)
