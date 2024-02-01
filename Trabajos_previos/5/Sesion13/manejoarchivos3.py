with open("test.txt", "r") as file1:  # Abre el archivo 'test.txt' en modo de lectura utilizando un gestor de contexto.
    read_content = file1.read()  # Lee el contenido completo del archivo.
    print(read_content)  # Imprime el contenido leído en la consola.
