# Importamos la librería matplotlib.pyplot para realizar gráficos.
import matplotlib.pyplot as plt

# Definimos dos listas que representarán los valores en los ejes.
x = [1, 2, 3, 4, 5]  # Valores para el eje X.
y = [10, 12, 5, 8, 14]  # Valores correspondientes para el eje Y.

# Creamos un gráfico de dispersión con los puntos definidos por las listas x e y.
plt.scatter(x, y, label='Puntos')  # Dibuja un gráfico de dispersión y etiqueta los puntos.

# Añadimos las etiquetas para los ejes y el título del gráfico.
plt.xlabel('Eje X')  # Establece la etiqueta para el eje X.
plt.ylabel('Eje Y')  # Establece la etiqueta para el eje Y.
plt.title('Gráfico de Dispersión')  # Establece el título del gráfico.

# Añadimos una leyenda para identificar los puntos en el gráfico.
plt.legend()  # Muestra la leyenda en el gráfico.

# Mostramos el gráfico generado.
plt.show()  # Despliega el gráfico en una ventana interactiva.
