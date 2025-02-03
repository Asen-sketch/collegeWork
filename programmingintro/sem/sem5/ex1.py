class Vehicle:
    def __init__(self, brand, model, year, price):
        self.brand = brand
        self.model = model
        self.year = year
        self.price = price

    def display_info(self):
        print(f"Brand: {self.brand}")
        print(f"Model: {self.model}")
        print(f"Year: {self.year}")
        print(f"Price: ${self.price}")

class Car(Vehicle):
    def __init__(self, brand, model, year, price, num_doors, coupe_style):
        super().__init__(brand, model, year, price)
        self.num_doors = num_doors
        self.coupe_style = coupe_style

    def display_info(self):
        super().display_info()
        print(f"Number of Doors: {self.num_doors}")
        print(f"Coupe Style: {self.coupe_style}")

class Truck(Vehicle):
    def __init__(self, brand, model, year, price, weight, body_length):
        super().__init__(brand, model, year, price)
        self.weight = weight
        self.body_length = body_length

    def display_info(self):
        super().display_info()
        print(f"Weight: {self.weight} kg")
        print(f"Body Length: {self.body_length} meters")

vehicle_example = Vehicle("Toyota", "Camry", 2022, 25000)
car_example = Car("BMW", "M3", 2023, 80000, 2, "Sport Coupe")
truck_example = Truck("Ford", "F-150", 2022, 35000, 2000, 5.5)

print("Vehicle Example:")
vehicle_example.display_info()
print("\nCar Example:")
car_example.display_info()
print("\nTruck Example:")
truck_example.display_info()
