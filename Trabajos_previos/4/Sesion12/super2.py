# Define the Mammal class
class Mammal:
    def mammal_info(self):
        print("Mammals can give direct birth.")

# Define the WingedAnimal class
class WingedAnimal:
    def winged_animal_info(self):
        print("Winged animals can flap.")

# Define the Bat class that inherits from both Mammal and WingedAnimal
class Bat(Mammal, WingedAnimal):
    pass

# Create an object of the Bat class
b1 = Bat()

# Call the methods to get information about Bat
b1.mammal_info()         # This will print information about mammals
b1.winged_animal_info()  # This will print information about winged animals
