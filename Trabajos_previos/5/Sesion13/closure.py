def calculate():
    num = 1
    def inner_func():
        nonlocal num  # Indica que la variable num se refiere a la definida en el ámbito superior.
        num += 2  # Incrementa la variable num en 2.
        return num  # Retorna la variable num modificada.
    return inner_func  # Retorna la función inner_func.

# llamar a la función externa
odd = calculate()  # odd es ahora un closure que recuerda el estado de num.

# llamar a la función interna
print(odd())  # Imprime 3, incrementando num a 3.
print(odd())  # Imprime 5, incrementando num a 5.
print(odd())  # Imprime 7, incrementando num a 7.

# llamar a la función externa nuevamente
odd2 = calculate()  # Crea un nuevo closure que inicia num en 1.
print(odd2())  # Imprime 3, incrementando num a 3.
