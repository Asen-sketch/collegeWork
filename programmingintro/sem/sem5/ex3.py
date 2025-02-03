import math

class Shape:
    def __init__(self, name, color):
        self.name = name
        self.color = color

    def describe(self):
        print(f"This is a {self.color} {self.name}.")

class Circle(Shape):
    def __init__(self, color, radius):
        super().__init__("Circle", color)
        self.radius = radius

    def area(self):
        return math.pi * self.radius ** 2

    def describe(self):
        super().describe()
        print(f"It has a radius of {self.radius} units.")

class Rectangle(Shape):
    def __init__(self, color, length, width):
        super().__init__("Rectangle", color)
        self.length = length
        self.width = width

    def area(self):
        return self.length * self.width

    def describe(self):
        super().describe()
        print(f"It has a length of {self.length} units and a width of {self.width} units.")

class Triangle(Shape):
    def __init__(self, color, base, height):
        super().__init__("Triangle", color)
        self.base = base
        self.height = height

    def area(self):
        return 0.5 * self.base * self.height

    def describe(self):
        super().describe()
        print(f"It has a base of {self.base} units and a height of {self.height} units.")

circle_example = Circle("Red", 5)
rectangle_example = Rectangle("Blue", 4, 6)
triangle_example = Triangle("Green", 3, 8)

print("Circle Example:")
circle_example.describe()
print(f"Area: {circle_example.area():.2f} square units\n")

print("Rectangle Example:")
rectangle_example.describe()
print(f"Area: {rectangle_example.area()} square units\n")

print("Triangle Example:")
triangle_example.describe()
print(f"Area: {triangle_example.area()} square units")
