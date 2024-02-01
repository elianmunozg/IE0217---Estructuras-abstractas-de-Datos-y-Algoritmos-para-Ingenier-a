import matplotlib.pyplot as plt  # Importamos la librería Matplotlib para realizar gráficos.

# Datos para el gráfico de pastel.
prop = [30, 20, 25, 15]  # Proporciones de cada segmento del pastel.
etiquetas = ['A', 'B', 'C', 'D']  # Etiquetas para cada segmento.

# Crear un gráfico de pastel.
plt.pie(prop, labels=etiquetas, autopct='%1.1f%%', startangle=140,
        colors=['gold', 'lightcoral', 'lightgreen', 'lightskyblue'])  # Se crean los segmentos con colores y porcentajes específicos.

# Añadir un título al gráfico.
plt.title('Gráfico de Pastel')  # Título del gráfico.

# Mostrar el gráfico.
plt.show()  # Despliega el gráfico en una ventana nueva.
