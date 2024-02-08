# Importamos la biblioteca 'requests', que nos permite hacer peticiones HTTP de manera sencilla en Python.
import requests

# Paso 1: Obtención de datos de usuarios
# --------------------------------------

# Realizamos una solicitud GET a la URL de la API que nos proporciona una lista de usuarios.
# Guardamos la respuesta HTTP obtenida en la variable 'users_response'.
users_response = requests.get('https://jsonplaceholder.typicode.com/users')

# Convertimos la respuesta, que esperamos que esté en formato JSON, a un objeto de Python (lista o diccionario) para su manipulación.
# Guardamos estos datos convertidos en la variable 'users_data'.
users_data = users_response.json()

# Paso 2: Obtención de datos de publicaciones
# -------------------------------------------

# Realizamos una solicitud GET similar a la anterior, pero esta vez para obtener publicaciones en lugar de usuarios.
# Guardamos la respuesta HTTP en la variable 'posts_response'.
posts_response = requests.get('https://jsonplaceholder.typicode.com/posts')

# Convertimos el texto de la respuesta en un objeto de Python para poder trabajar con los datos de las publicaciones.
# Guardamos estos datos en la variable 'posts_data'.
posts_data = posts_response.json()

# Paso 3: Procesamiento de datos
# ------------------------------

# Creamos un diccionario vacío llamado 'user_posts' que usaremos para asociar cada usuario con sus respectivas publicaciones.
user_posts = {}

# Iteramos sobre cada usuario en 'users_data'. Para cada uno, agregamos una entrada en 'user_posts' con una lista vacía como valor.
# Esto prepara el diccionario para almacenar publicaciones asociadas a cada ID de usuario.
for user in users_data:
    user_posts[user['id']] = []

# Iteramos sobre cada publicación en 'posts_data'. Usamos 'post.get('userId')' para obtener de manera segura el ID del usuario asociado
# (el método 'get' evita errores si la clave 'userId' no existe en el diccionario 'post').
for post in posts_data:
    user_id = post.get('userId')
    # Si encontramos que el ID de usuario ya existe en nuestro diccionario 'user_posts', agregamos la publicación a la lista correspondiente.
    if user_id in user_posts:
        user_posts[user_id].append({
            'title': post['title'],
            'body': post['body']
        })

# Paso 4: Presentación de resultados
# ----------------------------------

# Ahora mostramos la información procesada. Iteramos sobre los items del diccionario 'user_posts'.
for user_id, posts in user_posts.items():
    # Usamos una comprensión de lista y la función 'next' para buscar el usuario en 'users_data' por su ID.
    # Si el usuario no se encuentra, 'next' devuelve 'None'.
    user = next((user for user in users_data if user['id'] == user_id), None)

    # Si encontramos el usuario, imprimimos su nombre y correo electrónico, y luego cada una de sus publicaciones.
    if user:
        print(f"\nPublicaciones de {user['name']} ({user['email']}):\n")
        for post in posts:
            print(f"Título: {post['title']}\nCuerpo: {post['body']}\n")
    else:
        # Si no se encuentra el usuario, imprimimos un mensaje que indica que no se encontraron datos para ese ID de usuario.
        print(f"No se encontraron datos para el usuario con ID {user_id}")
