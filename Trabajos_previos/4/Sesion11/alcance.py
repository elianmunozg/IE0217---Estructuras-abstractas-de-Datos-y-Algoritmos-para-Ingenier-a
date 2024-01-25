

# declare global variable
message = 'Hello'

def greet():
    # declare local variable
    print('Local', message)

greet()
# accessing the global variable outside of the greet() function
print('Global', message)

# outside function
def outer():
    message = 'local'

    # nested function
    def inner():
        # declare nonlocal variable
        nonlocal message
        message = 'nonlocal'
        print("inner:", message)

    inner()
    print("outer:", message)

outer()

# global variable
c = 1

def add():
    # use of global keyword
    global c

    # increment c by 2
    c = c + 2

    # print the new value of c within the function
    print(c)

# Call the add() function to modify the global variable c
add()

# Print the global variable c outside the function
# The output will be 3 because the add() function has modified the global variable c
print(c)


def outer_function():
    num = 20

    def inner_function():
        global num
        num = 25

    print("Before calling inner_function(): ", num)
    inner_function()
    print("After calling inner_function(): ", num)

outer_function()

# This will print the global num which was modified by inner_function to 25
print("Outside both functions: ", num)
