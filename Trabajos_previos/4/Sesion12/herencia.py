# Defining the base class Animal
class Animal:
    # attribute of the parent class
    name = ""

    # method of the parent class
    def eat(self):
        print("I can eat")

# Defining the derived class Dog, which inherits from Animal
class Dog(Animal):
    # new method in the subclass
    def display(self):
        # accessing name attribute of the superclass using self
        print("My name is ", self.name)

# Creating an instance of the subclass Dog
labrador = Dog()

# Accessing superclass attribute and method
labrador.name = "Rohu"  # setting the name for the labrador instance
labrador.eat()  # calling the inherited method eat

# Calling the subclass method display
labrador.display()  # this will access the name attribute and print it
