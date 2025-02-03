def anagram(w1, w2):
    proc_w1 = w1.replace(" ", "").lower()
    proc_w2 = w2.replace(" ", "").lower()
    return sorted(proc_w1) == sorted(proc_w2)

word1 = input("Enter word one: ")
word2 = input("Enter word two: ")
result = anagram(word1, word2)

if result:
    print(f"'{word1}' and '{word2}' are anagrams.")
else:
    print(f"'{word1}' and '{word2}' are NOT anagrams.")