import numpy as np  # Para cálculos numéricos y manejo de arreglos.
import matplotlib.pyplot as plt  # Para visualización de datos.
# Para dividir datos en entrenamiento y prueba.
from sklearn.model_selection import train_test_split
# Para realizar regresión lineal.
from sklearn.linear_model import LinearRegression
# Para calcular métricas de error.
from sklearn.metrics import mean_absolute_error, mean_squared_error
from math import sqrt  # Para calcular la raíz cuadrada.

# Generamos datos de ejemplo para el modelo.
# Establece una semilla para que la aleatoriedad sea reproducible.
np.random.seed(42)
# Variables independientes generadas aleatoriamente.
X = 2 * np.random.rand(100, 1)
# Generamos la variable dependiente con una relación lineal y ruido.
y = 4 + 3 * X + np.random.randn(100, 1)

# Dividimos los datos en conjuntos de entrenamiento (80%) y prueba (20%).
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42)  # Función de scikit-learn para dividir los datos.

# Creamos y ajustamos el modelo de regresión lineal.
modelo = LinearRegression()  # Inicializamos el modelo de regresión lineal.
# Ajustamos el modelo usando el conjunto de entrenamiento.
modelo.fit(X_train, y_train)

# Hacemos predicciones utilizando el modelo en el conjunto de prueba.
y_pred = modelo.predict(X_test)  # Predicciones del modelo.

# Calculamos métricas de evaluación.
mae = mean_absolute_error(y_test, y_pred)  # Error absoluto medio.
mse = mean_squared_error(y_test, y_pred)  # Error cuadrático medio.
rmse = sqrt(mse)  # Raíz del error cuadrático medio.

# Cálculo de errores adicionales para la evaluación del modelo.
# Error absoluto relativo.
rae = np.sum(np.abs(y_test - y_pred)) / \
    np.sum(np.abs(y_test - np.mean(y_test)))
# Error cuadrático relativo.
rse = np.sum((y_test - y_pred)**2) / np.sum((y_test - np.mean(y_test))**2)

# Imprimimos los resultados de las métricas.
print(f"MAE: {mae:.2f}")
print(f"MSE: {mse:.2f}")
print(f"RMSE: {rmse:.2f}")
print(f"RAE: {rae:.2%}")
print(f"RSE: {rse:.2%}")

# Creamos una gráfica para visualizar los resultados.
# Gráfico de dispersión de los datos de prueba.
plt.scatter(X_test, y_test, label='Datos de prueba', color='blue')
# Línea de las predicciones del modelo.
plt.plot(X_test, y_pred, label='Predicciones', color='red')
plt.title('Regresión Lineal y Errores')  # Título del gráfico.
plt.xlabel('X')  # Etiqueta del eje X.
plt.ylabel('y')  # Etiqueta del eje Y.
plt.legend()  # Añadimos una leyenda.

# Mostramos los errores en la gráfica como líneas.
for i in range(len(X_test)):  # Iteramos sobre cada punto de prueba.
    # Líneas de error.
    plt.plot([X_test[i], X_test[i]], [y_test[i], y_pred[i]],
             linestyle='--', color='gray')

plt.show()  # Mostramos la gráfica con los datos, predicciones y errores.
