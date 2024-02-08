# Importamos la biblioteca requests, que nos permite enviar solicitudes HTTP de forma sencilla.
import requests

# Manejo de Respuesta
# --------------------

# Enviamos una solicitud GET a una URL específica. Esta URL se espera que devuelva datos en formato JSON.
response = requests.get('https://jsonplaceholder.typicode.com/todos/1')

# Imprimimos el código de estado de la respuesta HTTP. Un código 200 indica éxito, mientras que otros códigos indican diferentes tipos de errores.
print("Código de estado HTTP:", response.status_code)

# Imprimimos las cabeceras (headers) de la respuesta. Las cabeceras contienen metadatos y pueden incluir información como el tipo de contenido y el tamaño de la respuesta.
print("Cabeceras de la respuesta:", response.headers)

# Intentamos convertir el texto de la respuesta en JSON. Esto funcionará si la respuesta es del tipo 'application/json' y contiene datos JSON válidos.
# Esto imprimirá el JSON contenido en la respuesta.
print("Cuerpo de la respuesta en formato JSON:", response.json())

# Manejo de Errores
# ------------------

# Utilizamos un bloque try-except para manejar posibles errores que puedan ocurrir al hacer la solicitud GET.
try:
    # Realizamos una solicitud GET a una URL que probablemente no exista, lo cual debería resultar en un error HTTP.
    response = requests.get('https://ejemplo.com/pagina-inexistente')

    # Utilizamos raise_for_status() para generar una excepción si la respuesta contiene un código de estado que indique un error.
    # Esto es útil para asegurarnos de que procesamos solo respuestas exitosas.
    response.raise_for_status()

    # Si no se generó ninguna excepción, imprimimos el texto de la respuesta.
    print("Texto de la respuesta:", response.text)

# Capturamos la excepción HTTPError que se genera cuando raise_for_status() encuentra un código de error.
except requests.exceptions.HTTPError as err:
    # Imprimimos un mensaje de error personalizado que incluye la información de la excepción.
    print("Se ha producido un error HTTP:", err)
