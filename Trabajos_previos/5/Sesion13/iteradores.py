# definir una lista
my_list = [4, 7, 0]

# crear un iterador a partir de la lista
iterator = iter(my_list)

# obtener el primer elemento del iterador
print(next(iterator))  # imprime 4

# obtener el segundo elemento del iterador
print(next(iterator))  # imprime 7

# obtener el tercer elemento del iterador
print(next(iterator))  # imprime 0


# iterar sobre cada elemento de la lista
for element in my_list:
    print(element)  # imprime cada elemento de la lista