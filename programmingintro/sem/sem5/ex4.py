class Candy:
    def __init__(self, name, price, weight):
        self.name = name
        self.price = price
        self.weight = weight

    def display_info(self):
        print(f"Name: {self.name}")
        print(f"Price: ${self.price:.2f}")
        print(f"Weight: {self.weight} grams")

class Chocolate(Candy):
    def __init__(self, name, price, weight, cocoa_percentage, chocolate_type):
        super().__init__(name, price, weight)
        self.cocoa_percentage = cocoa_percentage
        self.chocolate_type = chocolate_type

    def display_info(self):
        super().display_info()
        print(f"Cocoa Percentage: {self.cocoa_percentage}%")
        print(f"Chocolate Type: {self.chocolate_type}")

class Gummy(Candy):
    def __init__(self, name, price, weight, aroma, form):
        super().__init__(name, price, weight)
        self.aroma = aroma
        self.form = form

    def display_info(self):
        super().display_info()
        print(f"Aroma: {self.aroma}")
        print(f"Form: {self.form}")

class HardCandy(Candy):
    def __init__(self, name, price, weight, taste, filling):
        super().__init__(name, price, weight)
        self.taste = taste
        self.filling = filling

    def display_info(self):
        super().display_info()
        print(f"Taste: {self.taste}")
        print(f"Filling: {self.filling}")

# Examples
chocolate_example = Chocolate("Dark Chocolate", 3.99, 100, 70, "Bitter")
gummy_example = Gummy("Fruit Gummies", 2.49, 150, "Fruity", "Animal Shapes")
hardcandy_example = HardCandy("Peppermint Drop", 1.29, 50, "Minty", "None")

# Displaying information
print("Chocolate Example:")
chocolate_example.display_info()
print("\nGummy Example:")
gummy_example.display_info()
print("\nHard Candy Example:")
hardcandy_example.display_info()
