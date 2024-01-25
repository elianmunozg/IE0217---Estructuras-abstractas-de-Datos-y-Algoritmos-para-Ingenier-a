# Define the base class Animal
class Animal:
    name = ""  # Attribute to store the name

    def eat(self):
        print("I can eat")  # Method to print that the animal can eat

# Create a subclass Dog that inherits from Animal
class Dog(Animal):
    # Override the eat() method
    def eat(self):
        super().eat()  # Call the eat() method of the superclass using super()
        print("I like to eat bones")  # Add a message specific to dogs

# Create an object of the Dog subclass
labrador = Dog()

# Call the eat() method on the labrador object
labrador.eat()
