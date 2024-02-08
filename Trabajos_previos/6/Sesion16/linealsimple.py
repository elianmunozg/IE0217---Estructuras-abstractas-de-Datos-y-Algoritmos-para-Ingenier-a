# Importamos las librerías necesarias para manipulación de datos, visualización y modelado.
import numpy as np  # Para operaciones numéricas y manejo de arreglos.
import matplotlib.pyplot as plt  # Para visualización de datos.
# Para dividir datos en entrenamiento y prueba.
from sklearn.model_selection import train_test_split
# Para realizar regresión lineal.
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score  # Para calcular la métrica R^2.

# Generamos un conjunto de datos sintéticos para la demostración.
# Fijamos la semilla para asegurar la reproducibilidad de los resultados.
np.random.seed(42)
# Creamos 100 puntos de datos aleatorios para la variable independiente X.
X = 2 * np.random.rand(100, 1)
# Generamos la variable dependiente y con una relación lineal y ruido gaussiano.
y = 4 + 3 * X + np.random.randn(100, 1)

# Dividimos los datos en conjuntos de entrenamiento (80%) y prueba (20%).
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42)  # Usamos train_test_split para dividir los datos.

# Inicializamos y entrenamos el modelo de regresión lineal con los datos de entrenamiento.
modelo = LinearRegression()  # Creamos una instancia de LinearRegression.
# Ajustamos el modelo a los datos de entrenamiento.
modelo.fit(X_train, y_train)

# Realizamos predicciones sobre el conjunto de prueba.
# Predecimos los valores de y usando el modelo ajustado.
y_pred = modelo.predict(X_test)

# Calculamos el coeficiente de determinación R^2 para evaluar la calidad del modelo.
# R^2 es una medida de cuán bien las predicciones se corresponden con los valores reales.
r2 = r2_score(y_test, y_pred)

# Visualizamos los resultados con una gráfica de dispersión y la línea de regresión.
# Puntos de prueba reales.
plt.scatter(X_test, y_test, label='Datos de prueba', color='blue')
# Línea de regresión.
plt.plot(X_test, y_pred,
         label=f'Regresión Lineal (R^2={r2:.2f})', color='orange')
# Título del gráfico.
plt.title('Regresión Lineal y Coeficiente de Determinación R^2')
plt.xlabel('X')  # Etiqueta del eje X.
plt.ylabel('y')  # Etiqueta del eje Y.
# Añadimos una leyenda para identificar los elementos del gráfico.
plt.legend()
plt.show()  # Mostramos la gráfica.
