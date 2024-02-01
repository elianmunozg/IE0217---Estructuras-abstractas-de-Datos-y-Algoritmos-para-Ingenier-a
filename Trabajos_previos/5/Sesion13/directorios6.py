import os  # Importa el módulo os.

# Crear un nuevo directorio llamado 'test'
os.mkdir('test')  # Crea un nuevo directorio en el CWD con el nombre 'test'.

os.listdir()  # Lista los contenidos del directorio actual.

# Renombrar un directorio
os.rename('test', 'new_one')  # Renombra el directorio 'test' a 'new_one'.

os.listdir()  # Lista los contenidos del directorio actual para verificar el cambio de nombre.

# La salida mostrará que el directorio 'test' ha sido renombrado a 'new_one'.
