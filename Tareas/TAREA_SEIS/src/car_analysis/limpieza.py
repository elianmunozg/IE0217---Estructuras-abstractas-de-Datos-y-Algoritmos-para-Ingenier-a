import pandas as pd

def limpiar_datos(datos):
    """
    Limpia el conjunto de datos realizando operaciones como eliminar valores faltantes
    y preparar variables categóricas.
    """

    # Eliminar filas con valores faltantes
    datos_limpios = datos.dropna()

    

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
