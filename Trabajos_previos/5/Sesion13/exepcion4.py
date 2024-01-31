try:
    numerator = 10  # Define el numerador como 10
    denominator = 0  # Define el denominador como 0, lo cual no es válido para una división.
    result = numerator/denominator  # Intenta realizar la división, lo que causará un error.
    print(result)  # Esta línea no se ejecutará debido al error anterior.
except:
    print("Error: Denominator cannot be 0.")  # Captura cualquier excepción y muestra un mensaje de error.
finally:
    print("This is finally block.")  # Este bloque se ejecuta siempre, haya ocurrido un error o no.
