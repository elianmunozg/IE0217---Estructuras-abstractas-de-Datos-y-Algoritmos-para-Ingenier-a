# Importamos NumPy para manejo de arreglos y operaciones matemáticas.
import numpy as np
# Importamos Matplotlib para la visualización de datos.
import matplotlib.pyplot as plt
# Función de scikit-learn para dividir los datos.
from sklearn.model_selection import train_test_split
# Modelo de regresión lineal de scikit-learn.
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score  # Métrica R^2 para evaluación del modelo.

# Generamos datos de ejemplo para modelado.
np.random.seed(42)  # Fijamos la semilla para garantizar la reproducibilidad.
# Creamos 100 puntos para la variable independiente X.
X = 2 * np.random.rand(100, 1)
# Definimos la variable dependiente y con una relación lineal más ruido aleatorio.
y = 4 + 3 * X + np.random.randn(100, 1)

# Dividimos los datos en conjuntos de entrenamiento y prueba.
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42)  # 80% para entrenamiento, 20% para prueba.

# Creamos y ajustamos el modelo de regresión lineal.
modelo = LinearRegression()  # Instanciamos el modelo de regresión lineal.
# Entrenamos el modelo con el conjunto de entrenamiento.
modelo.fit(X_train, y_train)

# Realizamos predicciones en el conjunto de prueba.
# Predecimos los valores de y para los datos de prueba.
y_pred = modelo.predict(X_test)

# Calculamos el coeficiente de determinación R^2 para evaluar el modelo.
# R^2 es una medida de la calidad de la predicción.
r2 = r2_score(y_test, y_pred)

# Visualizamos los resultados con una gráfica de dispersión para los datos reales y una línea para las predicciones.
# Datos reales como puntos.
plt.scatter(X_test, y_test, label='Datos de prueba', color='blue')
# Línea de regresión ajustada.
plt.plot(X_test, y_pred, label=f'Regresión Lineal (R^2={r2:.2f})', color='red')
# Título del gráfico.
plt.title('Regresión Lineal y Coeficiente de Determinación R^2')
plt.xlabel('X')  # Etiqueta para el eje X.
plt.ylabel('y')  # Etiqueta para el eje Y.
plt.legend()  # Añadimos una leyenda para identificar cada conjunto de datos.
plt.show()  # Mostramos la gráfica.
