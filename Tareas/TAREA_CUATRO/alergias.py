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

# Creación de la instancia de la clase Alergia y adición de las alergias
gestor_alergias = Alergia()
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


for nombre, valor in alergias_a_agregar.items():
    gestor_alergias.agregar_alergia(nombre, valor)

# Ejemplo de uso
gestor_alergias.imprimir_todas()
print("\nEjemplo de alergia específica:")
gestor_alergias.imprimir_especifica("Chocolate")

# Definición de la clase EvaluacionEspecifica
class EvaluacionEspecifica:
    def __init__(self, gestor_alergias):
        self.gestor_alergias = gestor_alergias

    def evaluar_alergias(self, puntuacion):
        alergias_personales = []
        for nombre, valor in self.gestor_alergias.alergias.items():
            if puntuacion & valor:
                alergias_personales.append((nombre, valor))
        return alergias_personales

    def imprimir_evaluacion(self, puntuacion):
        alergias_personales = self.evaluar_alergias(puntuacion)
        print(f"Puntuación total de alergias: {puntuacion}")
        if alergias_personales:
            print("Desglose de alergias:")
            for nombre, valor in alergias_personales:
                print(f"- {nombre} (Valor: {valor})")
        else:
            print("No se encontraron alergias para esta puntuación.")

# Ejemplo de uso con la puntuación 34
evaluador = EvaluacionEspecifica(gestor_alergias)
evaluador.imprimir_evaluacion(34)