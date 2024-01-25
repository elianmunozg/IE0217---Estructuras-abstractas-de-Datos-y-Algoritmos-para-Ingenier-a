# Class definition
class Bike:
    # class attributes
    name = ""
    gear = 0

# Creating an instance of the class Bike
bike1 = Bike()

# Modifying the attributes of the instance bike1
bike1.name = "Mountain Bike"
bike1.gear = 11

# Accessing the attributes of bike1 and printing them
print(f"Name: {bike1.name}, Gears: {bike1.gear}")
