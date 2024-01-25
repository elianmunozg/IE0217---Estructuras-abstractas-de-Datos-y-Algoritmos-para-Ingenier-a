# Define the SuperClass with a method super_method
class SuperClass:
    def super_method(self):
        print("Super Class method called")

# Define a class DerivedClass1 that derives from SuperClass
class DerivedClass1(SuperClass):
    def derived1_method(self):
        print("Derived class 1 method called")

# Define a class DerivedClass2 that derives from DerivedClass1
class DerivedClass2(DerivedClass1):
    def derived2_method(self):
        print("Derived class 2 method called")

# Create an object of DerivedClass2
d2 = DerivedClass2()

# Call methods on the d2 object
d2.super_method()       # Output: "Super Class method called"
d2.derived1_method()    # Output: "Derived class 1 method called"
d2.derived2_method()    # Output: "Derived class 2 method called"
