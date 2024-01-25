# Define the Bike class with a constructor
class Bike:
    def __init__(self, name=""):
        self.name = name

# Create an instance of Bike without a name
bike1 = Bike()

# Create an instance of Bike with a name
bike2 = Bike("Mountain Bike")

# Define the Point class with custom new and init methods
class Point(object):
    def __new__(cls, *args, **kwargs):
        print("From new")
        print(cls)
        print(args)
        print(kwargs)
        obj = super(Point, cls).__new__(cls)
        return obj

    def __init__(self, x=0.0, y=0.0):
        print("From init")
        self.x = x
        self.y = y

# Define a class that inherits from Point and limits the number of instances
class SqPoint(Point):
    MAX_INST = 4
    INST_CREATED = 0

    def __new__(cls, *args, **kwargs):
        if cls.INST_CREATED >= cls.MAX_INST:
            raise ValueError("Cannot create more objects")
        cls.INST_CREATED += 1
        return super(SqPoint, cls).__new__(cls)

# Creating instances of SqPoint
points = []
for i in range(5):
    try:
        points.append(SqPoint())
    except ValueError as e:
        print(e)

# Test printing of the Bike and Point objects
print(bike1.name)        # Output: ''
print(bike2.name)        # Output: 'Mountain Bike'
for point in points:
    print(point.x, point.y)  # Output: 0.0 0.0 for created instances
