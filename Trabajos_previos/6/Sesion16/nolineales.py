# Importamos las bibliotecas necesarias para la manipulación de datos y visualización gráfica.
import numpy as np
import matplotlib.pyplot as plt
# Importamos funciones y modelos de la biblioteca scikit-learn para realizar la división de datos,
# construir un modelo de regresión lineal, y aplicar regularización.
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
# Importamos herramientas para transformar las características en polinomios y para crear pipelines.
from sklearn.preprocessing import PolynomialFeatures
from sklearn.pipeline import make_pipeline

# Generar datos de ejemplo no lineales
np.random.seed(42)  # Fijar semilla para reproducibilidad
# Crear datos de entrada (X) y salida (y) con una relación no lineal
X = 2 * np.random.rand(100, 1)
y = X**2 + X + 2 + np.random.randn(100, 1)

# Visualizar datos no lineales
plt.scatter(X, y)  # Gráfico de dispersión de los datos originales
plt.title('Datos de Regresión No Lineal')  # Título del gráfico
plt.xlabel('X')  # Etiqueta del eje X
plt.ylabel('y')  # Etiqueta del eje Y
plt.show()  # Mostrar el gráfico

# Aplicar regresión polinómica de segundo grado
grado_polinomio = 2  # Grado del polinomio para la regresión
# Crear un modelo de regresión polinómica utilizando un 'pipeline'
# que primero transforma las características a un espacio polinomial
# y luego aplica regresión lineal en este espacio transformado
modelo_polinomico = make_pipeline(
    PolynomialFeatures(grado_polinomio), LinearRegression()
)
modelo_polinomico.fit(X, y)  # Ajustar el modelo con los datos

# Visualizar la regresión polinómica
X_test = np.linspace(0, 2, 100).reshape(
    100, 1)  # Generar puntos para la predicción
# Predecir valores con el modelo ajustado
y_pred = modelo_polinomico.predict(X_test)

plt.scatter(X, y)  # Gráfico de dispersión de los datos originales
# Gráfico de la línea de regresión polinómica
plt.plot(X_test, y_pred, color='red',
         label=f'Regresión Polinómica ({grado_polinomio} grado)')
plt.title('Regresión Polinómica')  # Título del gráfico
plt.xlabel('X')  # Etiqueta del eje X
plt.ylabel('y')  # Etiqueta del eje Y
plt.legend()  # Mostrar leyenda
plt.show()  # Mostrar el gráfico
