class Car:
    def __init__(self, car_brand, car_model, car_price, car_color, manifacture_year):
        self.car_brand = car_brand
        self.car_model = car_model
        self.car_price = car_price
        self.car_color = car_color
        self.manifacture_year = manifacture_year

    def display_info(self):
        print(f"{self.car_brand} | {self.car_model} | ${self.car_price} | {self.car_color} | {self.manifacture_year}")

cars = [
    Car("Brand1", "Model1", 25000, "Blue", 2021),
    Car("Brand2", "Model2", 22000, "Red", 2022),
    Car("Brand3", "Model3", 24000, "Black", 2020),
    Car("Brand4", "Model4", 35000, "White", 2022),
    Car("Brand5", "Model5", 50000, "Silver", 2024),
    Car("Brand6", "Model6", 24000, "Gray", 2019),
    Car("Brand7", "Model7", 70000, "Black", 2024)

]

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
        print(f"No {brand} cars found.")

def search_color(cars, color):
    matching = [car for car in cars if car.car_color.lower() == color.lower()]
    if matching:
        max_price_car = max(matching, key=lambda x: x.car_price)
        max_price_car.display_info()
    else:
        print(f"No {color} cars found.")

def newset_car(cars):
    newest = [car for car in cars if car.manifacture_year == 2022]
    return newest
