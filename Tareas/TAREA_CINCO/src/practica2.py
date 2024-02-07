import numpy as np

class GradeBook:
    """
    Una clase para manejar las calificaciones de estudiantes utilizando operaciones de NumPy.
    
    Attributes:
        grades (ndarray): Un array de NumPy que almacena las calificaciones de los estudiantes.
        
    Methods:
        calculate_student_averages(): Calcula el promedio de calificaciones por estudiante.
        calculate_subject_averages(): Calcula el promedio de calificaciones por asignatura.
        find_maximum_grades(): Encuentra la calificación máxima obtenida por cada estudiante.
        calculate_total_grades_by_subject(): Calcula la suma total de calificaciones por asignatura.
        display_results(): Imprime los resultados de los cálculos realizados.
    """
    
    def __init__(self):
        """Inicializa el GradeBook con un conjunto de datos de calificaciones generado aleatoriamente."""
        np.random.seed(0)  # Para reproducibilidad
        self.grades = np.random.randint(50, 100, size=(5, 5))

    def calculate_student_averages(self):
        """Calcula el promedio de calificaciones por estudiante."""
        return np.mean(self.grades, axis=1)

    def calculate_subject_averages(self):
        """Calcula el promedio de calificaciones por asignatura."""
        return np.mean(self.grades, axis=0)

    def find_maximum_grades(self):
        """Encuentra la calificación máxima obtenida por cada estudiante."""
        return np.max(self.grades, axis=1)

    def calculate_total_grades_by_subject(self):
        """Calcula la suma total de calificaciones por asignatura."""
        return np.sum(self.grades, axis=0)

    def display_results(self):
        """Imprime los resultados de los cálculos realizados."""
        print("Calificaciones de los estudiantes:")
        print(self.grades)
        print("\nPromedio de calificaciones por estudiante:")
        print(self.calculate_student_averages())
        print("\nPromedio de calificaciones por asignatura:")
        print(self.calculate_subject_averages())
        print("\nCalificación máxima obtenida por cada estudiante:")
        print(self.find_maximum_grades())
        print("\nSuma total de calificaciones por asignatura:")
        print(self.calculate_total_grades_by_subject())
# Crear instancia de GradeBook y mostrar los resultados
gradebook = GradeBook()
gradebook.display_results()