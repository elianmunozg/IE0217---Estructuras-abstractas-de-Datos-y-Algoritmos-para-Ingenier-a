class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __str__(self):
        return "({0},{1})".format(self.x, self.y)

    def __add__(self, other):
        x = self.x + other.x
        y = self.y + other.y
        return Point(x, y)

# Create two Point objects
p1 = Point(1, 2)
p2 = Point(2, 3)

# Add the two Point objects using the __add__ method
result = p1 + p2

# Print the result
print(result)


class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    # Overload the less than (<) operator
    def __lt__(self, other):
        return self.age < other.age

# Create two Person objects
p1 = Person("Alice", 20)
p2 = Person("Bob", 30)

# Compare the ages using the < operator
print(p1 < p2)  # This will print True because Alice is younger than Bob
print(p2 < p1)  # This will print False because Bob is not younger than Alice
