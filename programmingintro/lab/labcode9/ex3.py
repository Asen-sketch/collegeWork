with open("document.bin", "wb") as file:
    data_to_write = "This is good".encode("ascii")
    file.write(data_to_write)

with open("document.bin", "rb") as file:
    data_read = file.read()
    decoded_data = data_read.decode("ascii")

print(decoded_data)
