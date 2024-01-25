# Working with different types of variables
num1 = 5
print(num1, 'is of type', type(num1))

num2 = 2.0
print(num2, 'is of type', type(num2))

num3 = 1+2j
print(num3, 'is of type', type(num3))

# Working with strings and sets
name = 'Python'
print(name)

message = 'Python for beginners'
print(message)

student_id = {112, 114, 115, 116, 118}
print(student_id)

# Working with tuples and dictionaries
languages = ["Swift", "Java", "Python"]

product = ('Microsoft', 'Xbox', 499.99)

capital_city = {'Nepal': 'Kathmandu', 'Italy': 'Rome', 'England': 'London'}

print(languages[0])  # Swift
print(languages[2])  # Python

print(product[0])  # Microsoft
print(product[1])  # Xbox

print(capital_city)  # {'Nepal': 'Kathmandu', 'Italy': 'Rome', 'England': 'London'}
print(capital_city['Nepal'])  # Kathmandu
