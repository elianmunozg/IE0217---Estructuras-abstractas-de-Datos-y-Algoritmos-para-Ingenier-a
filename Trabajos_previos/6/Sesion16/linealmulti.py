import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.datasets import make_regression

# Generar datos sintéticos para regresión
# n_samples: número de muestras a generar
# n_features: número de características por muestra
# noise: desviación estándar del ruido gaussiano añadido a la salida
# random_state: semilla para la generación de números aleatorios para reproducibilidad de los resultados
X, y = make_regression(n_samples=100, n_features=3, noise=20, random_state=42)

# Crear un DataFrame de pandas para una mejor manipulación y visualización de los datos
# Las columnas representan las características 'Tamaño', 'Habitaciones', y 'Distancia_Ciudad'
# 'Precio' es la variable objetivo que tratamos de predecir
df = pd.DataFrame(X, columns=['Tamaño', 'Habitaciones', 'Distancia_Ciudad'])
df['Precio'] = y

# Dividir los datos en conjuntos de entrenamiento y prueba
# El conjunto de prueba será el 20% del total de los datos
# train_test_split divide aleatoriamente los datos mientras mantiene la proporción de los datos originales
X_train, X_test, Y_train, y_test = train_test_split(
    # Características para entrenamiento
    df[['Tamaño', 'Habitaciones', 'Distancia_Ciudad']],
    df['Precio'],  # Variable objetivo
    test_size=0.2,  # Proporción del conjunto de prueba
    random_state=42  # Semilla para reproducibilidad
)

# Crear y ajustar el modelo de regresión lineal múltiple
# LinearRegression crea un modelo que intenta predecir la variable dependiente (y) a partir de las independientes (X)
modelo = LinearRegression()
modelo.fit(X_train, Y_train)  # Ajusta el modelo con los datos de entrenamiento

# Imprimir los coeficientes e intercepción del modelo
# Coeficientes corresponden al impacto de cada característica independiente en la variable dependiente
# La intercepción es el valor de 'y' cuando todas las características son 0
print("Coeficientes:", modelo.coef_)
print("Intercepción:", modelo.intercept_)

# Realizar predicciones en el conjunto de prueba
# Utiliza el modelo ajustado para predecir los precios a partir del conjunto de prueba
y_pred = modelo.predict(X_test)

# Visualización de la regresión lineal múltiple con tres subplots
fig = plt.figure(figsize=(12, 6))

# Gráfica 1: Relación entre Tamaño, Habitaciones y Precio Verdadero
# 'projection='3d'' permite crear un gráfico tridimensional
ax1 = fig.add_subplot(131, projection='3d')
ax1.scatter(
    X_test['Tamaño'], X_test['Habitaciones'], y_test, c='blue', marker='o', alpha=0.5
)
ax1.set_xlabel('Tamaño')
ax1.set_ylabel('Habitaciones')
ax1.set_zlabel('Precio Verdadero')
ax1.set_title('Precio Verdadero vs. Tamaño y Habitaciones')

# Gráfica 2: Relación entre Tamaño, Habitaciones y Precio Predicho por el modelo
ax2 = fig.add_subplot(132, projection='3d')
ax2.scatter(
    X_test['Tamaño'], X_test['Habitaciones'], y_pred, c='red', marker='o', alpha=0.5
)
ax2.set_xlabel('Tamaño')
ax2.set_ylabel('Habitaciones')
ax2.set_zlabel('Precio Predicho')
ax2.set_title('Precio Predicho vs. Tamaño y Habitaciones')

# Gráfica 3: Comparación directa del Precio Verdadero y el Precio Predicho
# Un gráfico perfectamente lineal indicaría una predicción perfecta
ax3 = fig.add_subplot(133)
ax3.scatter(y_test, y_pred, c='green', alpha=0.5)
ax3.plot(
    [min(y_test), max(y_test)], [min(y_test), max(y_test)],
    linestyle='--', color='red', linewidth=2
)
ax3.set_xlabel('Precio Verdadero')
ax3.set_ylabel('Precio Predicho')
ax3.set_title('Comparación de Precio Verdadero y Precio Predicho')

# Ajusta el layout para evitar la superposición de elementos
plt.tight_layout()
plt.show()
