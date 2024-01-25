import random

# Prints a random number in the range 10 to 19
print(random.randrange(10, 20))

list1 = ['a', 'b', 'c', 'd', 'e']

# Prints a random item from list1
print(random.choice(list1))

# Shuffles list1 in place
random.shuffle(list1)

# Prints the shuffled list1
print(list1)

# Prints a random float number between 0 and 1
print(random.random())

# A list with 3 integers
numbers = [1, 2, 5]
print(numbers)
# Output: [1, 2, 5]

# List of programming languages
languages = ["Python", "Swift", "C++"]

# Access and print the first item in the list
print(languages[0])  # Outputs: Python

# Access and print the third item in the list
print(languages[2])  # Outputs: C++


# List slicing in Python
my_list = ['p', 'r', 'o', 'g', 'r', 'a', 'm', 'i', 'z']
print(my_list[2:5])  # items from index 2 to index 4
print(my_list[5:])   # items from index 5 to end
print(my_list[:])    # items beginning to end

# Accessing list items with negative indexing
languages = ["Python", "Swift", "C++"]
print(languages[-1])  # C++
print(languages[-3])  # Python

# Using various list methods
numbers = [21, 34, 54, 12]
print("Before Append:", numbers)
numbers.append(32)
print("After Append:", numbers)

languages = ['Python', 'Swift', 'C++']
languages[2] = 'C'  # changing the third item to 'C'
print(languages)  # ['Python', 'Swift', 'C']

# Joining two lists
prime_numbers = [2, 3, 5]
even_numbers = [4, 6, 8]
prime_numbers.extend(even_numbers)
print("List after append:", prime_numbers)

# Removing items from a list
languages = ['Python', 'Swift', 'C++', 'C', 'Java', 'Rust', 'R']
del languages[1]  # deleting the second item
print(languages)

del languages[-1]  # deleting the last item
print(languages)

del languages[0:2]  # delete first two items
print(languages)

languages = ['Python', 'Swift', 'C++', 'C', 'Java', 'Rust', 'R']
languages.remove('Python')  # remove 'Python' from the list
print(languages)

# Iterating through a list and printing each element
languages = ['Python', 'Swift', 'C++']
for language in languages:
    print(language)

# Checking membership in the list
print('C' in languages)  # False
print('Python' in languages)  # True

# Printing the list and the total number of elements
print("List: ", languages)
print("Total Elements: ", len(languages))  # 3

# Using list comprehensions to create lists
# List comprehension to create a list of squares
numbers = [number*number for number in range(1, 6)]
print(numbers)  # Output: [1, 4, 9, 16, 25]

# Equivalent list comprehension using exponentiation
numbers = [x**2 for x in range(1, 6)]
print(numbers)  # Output: [1, 4, 9, 16, 25]

# Manually creating a list of squares
numbers = []
for x in range(1, 6):
    numbers.append(x * x)
print(numbers)  # Output: [1, 4, 9, 16, 25]

# Different types of tuples
# Empty tuple
my_tuple = ()
print(my_tuple)

# Tuple having integers
my_tuple = (1, 2, 3)
print(my_tuple)

# Tuple with mixed datatypes
my_tuple = (1, "Hello", 3.4)
print(my_tuple)

# Nested tuple
my_tuple = ("mouse", [8, 4, 6], (1, 2, 3))
print(my_tuple)


# String creation and access
name = "Python"
print(name)

message = "I love Python."
print(message)

greet = 'hello'
print(greet[1])  # access 1st index element, prints "e"
print(greet[-4]) # access 4th last element, prints "e"

greet = 'Hello'
print(greet[1:4])  # access character from 1st index to 3rd index, prints "ell"

# String errors and manipulation
message = "Hola Amigos"
# message[0] = 'H'  # Uncommenting this line would raise a TypeError since strings are immutable

message = "Hola Amigos"
message = "Hello Friends"
print(message)  # prints "Hello Friends"

message = """
Never gonna give you up
Never gonna let you down
"""
print(message)  # prints the multiline string

# String comparisons and operations
str1 = "Hello, world!"
str2 = "I love Python."
str3 = "Hello, world!"

print(str1 == str2)  # compare str1 and str2, prints False
print(str1 == str3)  # compare str1 and str3, prints True

print('a' in 'program')  # True
print('at' not in 'battle')  # False

greet = 'Hello'
name = "Jack"
result = greet + ' ' + name
print(result)  # Output: Hello Jack

# Iterating through a string and counting its length
for letter in greet:
    print(letter)

print(len(greet))  # Output: 5

# String with escaped double quotes
example = "He said, \"What's there?\""
print(example)  # Output: He said, "What's there?"

# String with escaped single quotes
example = 'He said, "What\'s there?"'
print(example)  # Output: He said, "What's there?"

# Using f-strings for string interpolation
name = 'Cathy'
country = 'UK'
print(f'{name} is from {country}')  # Output: Cathy is from UK

# Working with sets and demonstrating set operations
# Define a set of numbers
numbers = {2, 4, 6, 6, 2, 8}
print(numbers)  # Sets automatically remove duplicates

# Add a number to the set
numbers.add(32)
print('Updated Set:', numbers)  # The set updates with the new number

# Merging sets
companies = {'Lacoste', 'Ralph Lauren'}
tech_companies = {'apple', 'google', 'apple'}  # Duplicates will be removed in the set
companies.update(tech_companies)
print(companies)  # Output: {'google', 'apple', 'Lacoste', 'Ralph Lauren'}

# Removing an item from a set
languages = {'Swift', 'Java', 'Python'}
languages.discard('Java')  # Java is removed from the set
print('Set after remove():', languages)  # Output: {'Swift', 'Python'}

# Note: The order of elements in a set is not guaranteed.

# Creating and printing sets and dictionaries
student_id = {112, 114, 116, 118, 115}
print('Student ID:', student_id)

vowel_letters = {'a', 'e', 'i', 'o', 'u'}
print('Vowel Letters:', vowel_letters)

mixed_set = {'Hello', 101, -2, 'Bye'}
print('Set of mixed data types:', mixed_set)

empty_set = set()
empty_dictionary = {}
print('Data type of empty_set:', type(empty_set))
print('Data type of empty_dictionary', type(empty_dictionary))

fruits = {"Apple", "Peach", "Mango"}
for fruit in fruits:
    print(fruit)

even_numbers = {2, 4, 6, 8}
print('Set:', even_numbers)
print('Total Elements:', len(even_numbers))

capital_city = {"Nepal": "Kathmandu", "Italy": "Rome", "England": "London"}
print(capital_city)

numbers = {1: "One", 2: "Two", 3: "Three"}
print(numbers)

capital_city['Japan'] = "Tokyo"
print("Updated Dictionary: ", capital_city)

# String manipulation and using f-strings
example = "He said, \"What's there?\""
print(example)

example = 'He said, "What\'s there?"'
print(example)

name = 'Cathy'
country = 'UK'
print(f'{name} is from {country}')

# Dictionary creation and manipulation
student_id = {111: "Eric", 112: "Kyle", 113: "Butters"}
print("Initial Dictionary: ", student_id)

# Updating an entry in the dictionary
student_id[112] = "Stan"
print("Updated Dictionary: ", student_id)

# Accessing entries in the dictionary
print(student_id[111])  # prints Eric
print(student_id[113])  # prints Butters

# Membership test for dictionary keys
squares = {1: 1, 3: 9, 5: 25, 7: 49, 9: 81}
print(1 in squares)  # prints True
print(2 not in squares)  # prints True
print(49 in squares)  # prints False, because 49 is a value, not a key

# Iterating through a dictionary
for i in squares:
    print(squares[i])  # prints the values: 1, 9, 25, 49, 81



