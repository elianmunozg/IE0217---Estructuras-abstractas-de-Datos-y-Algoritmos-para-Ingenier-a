# Define SuperClass1 with a method info
class SuperClass1:
    def info(self):
        print("Super Class 1 method called")

# Define SuperClass2 with a method info
class SuperClass2:
    def info(self):
        print("Super Class 2 method called")

# Define Derived class that inherits from SuperClass1 and SuperClass2
class Derived(SuperClass1, SuperClass2):
    pass

# Create an object of the Derived class
d1 = Derived()

# Call the info method on the d1 object
d1.info()
