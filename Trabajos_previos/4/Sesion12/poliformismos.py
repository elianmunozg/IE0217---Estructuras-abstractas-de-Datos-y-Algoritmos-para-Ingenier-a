from math import pi

# Define a base class Polygon
class Polygon:
    def render(self):
        print("Rendering Polygon...")

# Define a base class Shape
class Shape:
    def __init__(self, name):
        self.name = name

    def area(self):
        pass

    def fact(self):
        pass

# Define a class Square that inherits from Polygon and Shape
class Square(Polygon, Shape):
    def __init__(self, length):
        super().__init__("Square")
        self.length = length

    def render(self):
        print("Rendering Square...")

    def area(self):
        return self.length**2

    def fact(self):
        return "Squares have each angle equal to 90 degrees."

# Define a class Circle that inherits from Polygon and Shape
class Circle(Polygon, Shape):
    def __init__(self, radius):
        super().__init__("Circle")
        self.radius = radius

    def render(self):
        print("Rendering Circle...")

    def area(self):
        return pi * self.radius**2

    def fact(self):
        return "I am a two-dimensional shape."

# Create an object of Square with a length of 4
s1 = Square(4)
s1.render()

# Create an object of Circle with a radius of 7
c1 = Circle(7)
c1.render()

# Print information about the Circle object
print(c1)
print(c1.fact())
print(s1.fact())
print(c1.area())
