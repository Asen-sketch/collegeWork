with open("document.bin", "rb") as file:
    letters = file.read(4)
    print(letters)
