import matplotlib.pyplot as plt
import numpy as np
import operator
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures
from sklearn.metrics import mean_squared_error, r2_score, mean_absolute_error
from sklearn.model_selection import train_test_split

def plot_results(X_test, y_test, y_pred, title, xlabel, ylabel):
    """
    Función auxiliar para graficar los resultados de la regresión.
    """
    plt.figure(figsize=(10, 6))  # Ajusta el tamaño de la figura
    plt.scatter(X_test, y_test, color='blue', label='Datos reales', alpha=0.5)
    plt.plot(X_test, y_pred, color='red', label='Modelo ajustado', linewidth=2)
    plt.title(title, fontsize=16)
    plt.xlabel(xlabel, fontsize=14)
    plt.ylabel(ylabel, fontsize=14)
    plt.legend()
    plt.grid(True)
    plt.show()

def realizar_analisis(X, y, titulo, xlabel='Variable Independiente', ylabel='Variable Dependiente', es_lineal=True, grado=2):
    """
    Realiza y grafica una regresión lineal o polinomial basada en los parámetros.
    También evalúa el modelo utilizando MSE, R² y MAE.
    """
    # Dividir datos
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
    
    if es_lineal:
        modelo = LinearRegression()
        modelo.fit(X_train, y_train)
        X_test_sorted = X_test
    else:  # Regresión polinomial
        poly_features = PolynomialFeatures(degree=grado)
        X_train_poly = poly_features.fit_transform(X_train)
        X_test_poly = poly_features.transform(X_test)
        
        modelo = LinearRegression()
        modelo.fit(X_train_poly, y_train)
        # Generar predicciones en un rango continuo para visualización
        X_range = np.linspace(X.min(), X.max(), 100).reshape(-1, 1)
        X_test_sorted = poly_features.transform(X_range)

    # Predicciones
    y_pred = modelo.predict(X_test_poly if not es_lineal else X_test)
    y_pred_sorted = modelo.predict(X_test_sorted)
    
    # Evaluación
    mse = mean_squared_error(y_test, y_pred)
    r2 = r2_score(y_test, y_pred)
    mae = mean_absolute_error(y_test, y_pred)
    print(f"{titulo} - MSE: {mse}, R²: {r2}, MAE: {mae}")
    
    # Gráfico
    plt.figure(figsize=(10, 6))
    plt.scatter(X_test, y_test, color='blue', label='Datos reales', alpha=0.5)
    if es_lineal:
        plt.plot(X_test, y_pred, 'r-', label='Regresión Lineal')
    else:
        # Para regresión polinomial, se grafica la curva ajustada
        X_range_sorted = np.linspace(X.min(), X.max(), 100).reshape(-1, 1)
        plt.plot(X_range_sorted, y_pred_sorted, 'r-', label='Regresión Polinomial')
    plt.title(titulo)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.legend()
    plt.show()