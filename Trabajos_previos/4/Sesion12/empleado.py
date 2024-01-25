# Class definition for Employee
class Employee:
    # Class attribute
    employee_id = 0

# Creating two instances of the Employee class
employee1 = Employee()
employee2 = Employee()

# Assigning values to the instance attributes
employee1.employee_id = 1001
employee2.employee_id = 1002

# Printing the employee IDs
print(f"Employee ID: {employee1.employee_id}")
print(f"Employee ID: {employee2.employee_id}")

# Class definition for Room
class Room:
    # Class attributes
    length = 0.0
    breadth = 0.0

    # Method to calculate the area of the Room
    def calculate_area(self):
        print("Area of Room =", self.length * self.breadth)

# Creating an instance of the Room class
study_room = Room()

# Assigning values to the attributes
study_room.length = 42.5
study_room.breadth = 30.8

# Calculating and printing the area of the room
study_room.calculate_area()
