import timeit

#Se crea de nuevo la clase Alergia
class Alergia:
    def __init__(self):
        self.alergias = {}

    def agregar_alergia(self, nombre, valor):
        self.alergias[nombre] = valor

    def imprimir_todas(self):
        for nombre, valor in self.alergias.items():
            print(f"Alergia: {nombre}, Valor: {valor}")

    def imprimir_especifica(self, nombre):
        if nombre in self.alergias:
            valor = self.alergias[nombre]
            print(f"Alergia: {nombre}, Valor: {valor}")
        else:
            print(f"No se encontró la alergia: {nombre}")




# Función para medir el rendimiento de agregar_alergia
def medir_agregar_alergia():
    alergias_a_agregar = {
    "Huevos": 1, "Cacahuetes": 2, "Mariscos": 4, "Fresas": 8, "Tomates": 16,
    "Chocolate": 32, "Polen": 64, "Gatos": 128, "Sardinas": 256, "Gluten": 512,
    "Almendras": 536870912, "Canela": 1073741824, "Altramuces": 2147483648, 
    "Mantequilla": 4294967296, "Pepino": 8589934592, "Cangrejo": 17179869184, 
    "Almejas": 34359738368, "Anacardos": 68719476736, "Coliflor": 137438953472, 
    "Pimienta": 274877906944, "Arándanos": 549755813888, "Pera": 1099511627776, 
    "Cerveza": 2199023255552, "Guisantes": 4398046511104, "Ciruelas": 8796093022208, 
    "Trigo": 17592186044416, "Higos": 35184372088832, "Centeno": 70368744177664, 
    "Pistachos": 140737488355328, "Cangrejo de río": 281474976710656, "Col": 562949953421312,
    "Huevo": 1024, "Nueces": 2048, "Leche": 4096, "Soja": 8192, "Miel": 16384,
    "Piña": 32768, "Ajo": 65536, "Maíz": 131072, "Kiwi": 262144, "Menta": 524288,
    "Gambas": 1048576, "Apio": 2097152, "Pescado": 4194304, "Manzanas": 8388608,
    "Cilantro": 16777216, "Aguacate": 33554432, "Zanahorias": 67108864, "Berenjenas": 134217728,
    "Lentejas": 268435456
}

    gestor_alergias = Alergia()
    for nombre, valor in alergias_a_agregar.items():
        gestor_alergias.agregar_alergia(nombre, valor)

# Ejecutar la medición
numero_de_ejecuciones = 100
tiempo = timeit.timeit(medir_agregar_alergia, number=numero_de_ejecuciones)
print(f"Tiempo promedio para agregar 50 alergias en {numero_de_ejecuciones} ejecuciones: {tiempo/numero_de_ejecuciones} segundos")
