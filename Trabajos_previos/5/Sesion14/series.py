import pandas as pd

# Crear una Serie de pandas con una lista de edades y asignar un nombre a la Serie.
ages = pd.Series([22, 35, 58], name="Age")

# Acceder a la columna 'Age' de un DataFrame y mostrarla.
df["Age"]

# Salida:
# 22
# 35
# 58
# Name: Age, dtype: int64

df.describe()#proporciona una descripción general rápida de los datos numéricos en un DataFrame