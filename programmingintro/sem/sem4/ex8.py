import math

def rectangle_area(length, width):
    return length * width

def rectangle_perimeter(length, width):
    return 2 * (length + width)

def circle_area(radius):
    return math.pi * radius**2

def circle_perimeter(radius):
    return 2 * math.pi * radius

def triangle_area(base, height):
    return 0.5 * base * height

def triangle_perimeter(side1, side2, side3):
    return side1 + side2 + side3

print("Select a geometric shape:")
print("1. Rectangle")
print("2. Circle")
print("3. Triangle")

choice = int(input("Enter the number of the selected shape: "))

match choice:
    case 1:
        length = float(input("Enter the length of the rectangle: "))
        width = float(input("Enter the width of the rectangle: "))
        area = rectangle_area(length, width)
        perimeter = rectangle_perimeter(length, width)
    case 2:
        radius = float(input("Enter the radius of the circle: "))
        area = circle_area(radius)
        perimeter = circle_perimeter(radius)
    case 3:
        base = float(input("Enter the base of the triangle: "))
        height = float(input("Enter the height of the triangle: "))
        area = triangle_area(base, height)
        side1 = float(input("Enter the length of side 1: "))
        side2 = float(input("Enter the length of side 2: "))
        side3 = float(input("Enter the length of side 3: "))
        perimeter = triangle_perimeter(side1, side2, side3)


print(f"\nArea: {area:.2f}")
print(f"Perimeter: {perimeter:.2f}")