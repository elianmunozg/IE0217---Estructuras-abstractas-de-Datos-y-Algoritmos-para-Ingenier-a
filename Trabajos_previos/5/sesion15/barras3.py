import matplotlib.pyplot as plt  # Importa la librería matplotlib para la creación de gráficos.

# Datos para el gráfico de barras.
categorias = ['A', 'B', 'C', 'D']  # Lista de categorías que aparecerán en el eje X.
valores = [15, 8, 12, 10]  # Lista de valores que aparecerán en el eje Y, correspondientes a cada categoría.

# Dibuja el gráfico de barras.
plt.bar(categorias, valores, color='royalblue', edgecolor='black')  # Crea barras verticales con bordes negros.

# Configuración de las etiquetas y título del gráfico con tamaños de fuente específicos.
plt.xlabel('Categorías', fontsize=12)  # Etiqueta del eje X con tamaño de fuente 12.
plt.ylabel('Valores', fontsize=12)  # Etiqueta del eje Y con tamaño de fuente 12.
plt.title('Gráfico de Barras', fontsize=14)  # Título del gráfico con tamaño de fuente 14.

# Configuración adicional para mejorar la estética y legibilidad del gráfico.
plt.xticks(rotation=45)  # Rota las etiquetas del eje X en un ángulo de 45 grados para mejor legibilidad.
plt.grid(axis='y', linestyle='--', alpha=0.7)  # Añade una rejilla horizontal con estilo de línea punteada y transparencia.

# Añadir etiquetas de valor sobre cada barra.
for i, v in enumerate(valores):
    plt.text(i, v + 0.5, str(v), ha='center', va='bottom', fontsize=10)  # Coloca el valor numérico encima de cada barra.

plt.show()  # Muestra el gráfico generado.
