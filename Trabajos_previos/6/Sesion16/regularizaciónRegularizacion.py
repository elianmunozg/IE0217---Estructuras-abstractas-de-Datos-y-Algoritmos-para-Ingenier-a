import numpy as np  # NumPy para cálculos numéricos y manejo de arreglos.
import matplotlib.pyplot as plt  # Matplotlib para visualización de datos.
# Para dividir datos en entrenamiento y prueba.
from sklearn.model_selection import train_test_split
# Modelos de regresión.
from sklearn.linear_model import LinearRegression, Lasso, Ridge
# Para transformar características a un espacio polinomial.
from sklearn.preprocessing import PolynomialFeatures
# Para crear pipelines de transformaciones y modelo.
from sklearn.pipeline import make_pipeline

# Generar datos de ejemplo no lineales
np.random.seed(42)  # Fijamos la semilla para reproducibilidad.
# Creamos datos aleatorios para la variable independiente X.
X = 2 * np.random.rand(100, 1)
# Generamos la variable dependiente y con una relación cuadrática y ruido.
y = 0.5 * X**2 + X + 2 + np.random.randn(100, 1)

# Dividir los datos en conjunto de entrenamiento y prueba
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42)  # División en 80% entrenamiento, 20% prueba.

# Crear modelo de regresión polinómica de grado 2
modelo_polinomico = make_pipeline(
    PolynomialFeatures(degree=2), LinearRegression())  # Pipeline que incluye transformación polinómica y regresión lineal.
# Ajustar el modelo polinómico a los datos de entrenamiento.
modelo_polinomico.fit(X_train, y_train)

# Crear modelo Lasso (L1)
modelo_lasso = make_pipeline(
    PolynomialFeatures(degree=2), Lasso(alpha=0.1))  # Pipeline con Lasso para regularización L1.
# Ajustar el modelo Lasso a los datos de entrenamiento.
modelo_lasso.fit(X_train, y_train)

# Crear modelo Ridge (L2)
modelo_ridge = make_pipeline(
    PolynomialFeatures(degree=2), Ridge(alpha=0.1))  # Pipeline con Ridge para regularización L2.
# Ajustar el modelo Ridge a los datos de entrenamiento.
modelo_ridge.fit(X_train, y_train)

# Visualizar los resultados
# Ordenamos los datos de prueba y las predicciones para una visualización más clara en la gráfica.
X_test_sorted, y_pred_polinomico_sorted = zip(
    *sorted(zip(X_test, modelo_polinomico.predict(X_test))))
X_test_sorted, y_pred_lasso_sorted = zip(
    *sorted(zip(X_test, modelo_lasso.predict(X_test))))
X_test_sorted, y_pred_ridge_sorted = zip(
    *sorted(zip(X_test, modelo_ridge.predict(X_test))))

# Gráfico de dispersión de los datos de prueba.
plt.scatter(X_test, y_test, label='Datos de prueba', color='blue')
# Líneas para las predicciones de los modelos.
plt.plot(X_test_sorted, y_pred_polinomico_sorted,
         label='Regresión Polinómica', color='orange')
plt.plot(X_test_sorted, y_pred_lasso_sorted, label='Lasso (L1)', color='red')
plt.plot(X_test_sorted, y_pred_ridge_sorted, label='Ridge (L2)', color='green')

# Títulos y etiquetas para la gráfica.
plt.title('Comparación de Modelos con Regularización')
plt.xlabel('X')
plt.ylabel('y')
plt.legend()  # Leyenda para identificar cada modelo.
plt.show()  # Mostrar la gráfica.
