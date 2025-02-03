class Car:
    def __init__(self, car_brand, car_model, car_price, car_color, manufacture_year):
        self.car_brand = car_brand
        self.car_model = car_model
        self.car_price = car_price
        self.car_color = car_color
        self.manufacture_year = manufacture_year

    def display_info(self):
        print(f"{self.car_brand} {self.car_model} ({self.manufacture_year}), Color: {self.car_color}, Price: ${self.car_price}")


def sort_price(cars):
    sorted_cars = sorted(cars, key=lambda x: x.car_price, reverse=True)
    for car in sorted_cars:
        car.display_info()


def list_by_brand(cars, brand):
    brand_cars = [car for car in cars if car.car_brand.lower() == brand.lower()]
    if brand_cars:
        for car in brand_cars:
            car.display_info()
    else:
        print(f"No cars found for the brand: {brand}")


def search_color(cars, color):
    matching_cars = [car for car in cars if car.car_color.lower() == color.lower()]
    if matching_cars:
        max_price_car = max(matching_cars, key=lambda x: x.car_price)
        max_price_car.display_info()
    else:
        print(f"No cars found with the color: {color}")


def newest_car(cars):
    newest_cars = [car for car in cars if car.manufacture_year == 2022]
    return newest_cars


cars = [
    Car("Toyota", "Camry", 25000, "Blue", 2021),
    Car("Honda", "Civic", 22000, "Red", 2022),
    Car("Ford", "Mustang", 35000, "Black", 2020),
    Car("Chevrolet", "Malibu", 28000, "White", 2022),
    Car("Tesla", "Model 3", 50000, "Silver", 2022),
    Car("Nissan", "Altima", 24000, "Gray", 2019),
    Car("BMW", "X5", 60000, "Black", 2022)
]

print("All Cars:")
for car in cars:
    car.display_info()

print("\nSorted by Price (Descending):")
sort_price(cars)

print("\nCars by Brand (Honda):")
list_by_brand(cars, "Honda")

print("\nSearch by Color (Black):")
search_color(cars, "Black")

print("\nNewest Cars (Manufactured in 2022):")
newest_cars = newest_car(cars)
for car in newest_cars:
    car.display_info()
