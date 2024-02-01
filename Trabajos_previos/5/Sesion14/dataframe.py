
import pandas as pd  # Importa la librería pandas con el alias pd.

# Creación de un DataFrame con pandas.
df = pd.DataFrame(
    {
        "Name": [  # Columna de nombres con tres entradas.
            "Braund, Mr. Owen Harris",
            "Allen, Mr. William Henry",
            "Bonnell, Miss Elizabeth",
        ],
        "Age": [22, 35, 58],  # Columna de edades con tres entradas correspondientes a cada nombre.
        "Sex": ["male", "male", "female"],  # Columna de género con tres entradas correspondientes.
    }
)

df  # Muestra el DataFrame creado.
