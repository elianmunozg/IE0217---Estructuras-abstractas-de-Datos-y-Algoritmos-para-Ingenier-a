class Polygon:
    def __init__(self, no_of_sides):
        self.n = no_of_sides
        self.sides = [0 for i in range(no_of_sides)]

    def inputSides(self):
        self.sides = [float(input(f"Enter side {str(i+1)}: ")) for i in range(self.n)]

    def dispSides(self):
        for i in range(self.n):
            print(f"Side {i+1} is {self.sides[i]}")

class Triangle(Polygon):
    def __init__(self):
        Polygon.__init__(self, 3)

    def findArea(self):
        a, b, c = self.sides
        # Calculate the semi-perimeter
        s = (a + b + c) / 2
        # Calculate the area using Heron's formula
        area = (s*(s-a)*(s-b)*(s-c)) ** 0.5
        print(f'The area of the triangle is {area:.2f}')

# Example usage:
# Create a triangle object
t = Triangle()
t.inputSides()  # Suppose the sides entered are 3, 4, 5
t.dispSides()
t.findArea()
