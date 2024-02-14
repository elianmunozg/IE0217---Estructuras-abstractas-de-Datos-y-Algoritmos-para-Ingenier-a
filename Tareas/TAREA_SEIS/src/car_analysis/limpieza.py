import pandas as pd

def limpiar_datos(datos):
    """
    Limpia el conjunto de datos realizando operaciones como eliminar valores faltantes
    y preparar variables categóricas.
    """

    # Eliminar filas con valores faltantes
    datos_limpios = datos.dropna()

    # Opcional: Convertir 'year' a 'vehicle_age'
    # Si decides calcular la edad del vehículo, descomenta las siguientes líneas:
    # datos_limpios['vehicle_age'] = 2023 - datos_limpios['year']
    # datos_limpios.drop(columns=['year'], inplace=True)
    
    # Asegurarse de que no se elimine 'year' si se va a utilizar directamente
    # Mantener la columna 'year' como está si no se realiza la transformación a 'vehicle_age'

    # Codificación de variables categóricas con pd.get_dummies
    categoricas = ['fuel', 'seller_type', 'transmission', 'owner']
    datos_limpios = pd.get_dummies(datos_limpios, columns=categoricas, drop_first=True)

    return datos_limpios

def preparar_datos_transmision(datos_limpios):
    # Esto asume que `datos_limpios` ya tiene variables dummy para 'transmission'
    # Por ejemplo: 'transmission_Manual' y 'transmission_Automatic' (si aplicable)
    X = datos_limpios[['transmission_Manual']]  # Usamos solo una de las dummies si son binarias
    y = datos_limpios['selling_price']
    return X, y
