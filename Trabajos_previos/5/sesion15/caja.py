import matplotlib.pyplot as plt  # Importa la librería de Matplotlib para la creación de gráficos.

# Datos para el gráfico de caja.
datos = [15, 25, 30, 35, 40, 45, 50, 60, 70, 80, 90]

# Crear un gráfico de caja.
plt.boxplot(datos)  # Crea un boxplot con la lista de datos proporcionada.

# Configuración de las etiquetas y el título del gráfico.
plt.ylabel('Valores')  # Establece 'Valores' como etiqueta para el eje Y.
plt.title('Gráfico de Caja')  # Establece 'Gráfico de Caja' como título del gráfico.

# Muestra el gráfico.
plt.show()  # Abre la ventana del visualizador para mostrar el gráfico.
