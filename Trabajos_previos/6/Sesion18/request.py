import requests

# Realizamos una solicitud GET a una API de ejemplo que proporciona datos en formato JSON.
response = requests.get('https://jsonplaceholder.typicode.com/todos/1')

# Imprimimos el tipo del objeto 'response' para ver la clase a la que pertenece, que debería ser 'requests.models.Response'.
print("Tipo:", type(response))

# Imprimimos el objeto 'response' directamente, lo cual generalmente muestra el código de estado HTTP de la respuesta.
print("Respuesta:", response)

# Imprimimos el contenido de la respuesta en formato texto. Esto es útil cuando la respuesta es una cadena de texto como HTML o JSON.
print("Respuesta text:", response.text)

# El último print está tratando de imprimir el atributo `__dict__` del objeto 'response'.
# `__dict__` es un diccionario que contiene todos los atributos del objeto, útil para la introspección.
print("Respuesta:", response.__dict__)

# Importamos la biblioteca 'requests' que nos permite enviar solicitudes HTTP de manera sencilla
import requests

# Definimos la URL de destino para nuestra solicitud GET. En este caso, estamos utilizando la página principal de Google.
url = "https://www.google.com"

# Enviamos una solicitud GET a la URL especificada. La función 'get' de 'requests' realiza la solicitud y obtiene la respuesta del servidor.
response = requests.get(url)

# La variable 'response' ahora contiene la respuesta del servidor a nuestra solicitud GET.
# La propiedad 'text' de esta respuesta contiene el contenido de la respuesta en formato de texto,
# que para una página web es típicamente HTML.

# Imprimimos el contenido de texto de la respuesta para ver el HTML de la página de Google.
# Si la solicitud fue exitosa, deberíamos ver el HTML que forma la página de inicio de Google.
print(response.text)

# Importamos la biblioteca requests para realizar solicitudes HTTP fácilmente
import requests

# Ejemplo de solicitud GET
# #########################
# Creamos un diccionario con los parámetros que queremos enviar en la URL
payload = {'clave1': 'valor1', 'clave2': 'valor2'}

# Realizamos una solicitud GET, pasando la URL y el diccionario de parámetros
response = requests.get('https://ejemplo.com/ruta', params=payload)

# Imprimimos el contenido de la respuesta de la solicitud GET
print(response.text)


# Ejemplo de solicitud POST enviando datos como formulario
# ########################################################
# Creamos un diccionario con los datos que queremos enviar en el cuerpo de la solicitud POST
payload = {'usuario': 'juan', 'contrasena': 'secreta'}

# Realizamos una solicitud POST, pasando la URL y el diccionario de datos como formulario
response = requests.post('https://ejemplo.com/login', data=payload)

# Imprimimos el contenido de la respuesta de la solicitud POST
print(response.text)


# Ejemplo de solicitud POST enviando datos como JSON
# ##################################################
# Creamos un diccionario con los datos que queremos enviar en el cuerpo de la solicitud POST
payload = {'usuario': 'juan', 'contrasena': 'secreta'}

# Realizamos una solicitud POST, pasando la URL y el diccionario de datos como JSON
response = requests.post('https://ejemplo.com/login', json=payload)

# Imprimimos el contenido de la respuesta de la solicitud POST
print(response.text)
