# Tarea 3
Esta tarea se basa en la implementación de STL de C++ junto con aplicación de sobrecarga de operadores y expresiones regulares. Para esto se implementaron dos programas uno consiste en una calculadora matricial en el ejemplo se realizó con una compleja sin embargo también funciona para hacer operaciones simples, y el segundo en un prgrama de validación de correo eléctronico, para compilar el programa basta con utilizar el comando make.
## Templates

### 1. Definición de Templates
Los templates en C++ permiten escribir código genérico que puede trabajar con cualquier tipo de dato. Se utilizan principalmente para la creación de funciones y clases genéricas.

**Ejemplo:**
```cpp
template <typename T>
T suma(T a, T b) {
    return a + b;
}
```

### 2. Sobrecarga de Plantillas
La sobrecarga de plantillas se refiere a la creación de múltiples versiones de una función template con diferentes sets de parámetros.

**Ejemplo:**
```cpp
template <typename T>
T maximo(T a, T b) {
return (a > b) ? a : b;
}

template <typename T>
T maximo(T a, T b, T c) {
return maximo(maximo(a, b), c);
}
```

### 3. Plantillas de Clases
Las plantillas de clases permiten definir una clase con tipos de datos genéricos, que se especifican al instanciar objetos de la clase.

**Ejemplo:**
```cpp
template <typename T>
class Caja {
public:
T contenido;
void setContenido(T nuevoContenido) {
contenido = nuevoContenido;
}
T getContenido() {
return contenido;
}
};
```

## Excepciones

### 4. Manejo de Excepciones
El manejo de excepciones en C++ se realiza a través de los bloques `try`, `catch` y `throw`.

**Ejemplo:**
```cpp
try {
// Código que puede lanzar una excepción
throw std::runtime_error("Error encontrado");
} catch (std::runtime_error &e) {
// Manejo de la excepción
std::cout << "Excepción capturada: " << e.what() << std::endl;
}
```

### 5. Excepciones Estándar
Algunas excepciones estándar en C++ incluyen `std::runtime_error`, `std::out_of_range`, y `std::invalid_argument`.

**Ejemplo:**
```cpp
// std::out_of_range puede ser útil al acceder a elementos fuera de los límites de un contenedor.
// std::invalid_argument se utiliza para argumentos inválidos en funciones
```

### 6. Política de Manejo de Excepciones
Una política de manejo de excepciones define cómo y cuándo se deben lanzar, capturar y manejar las excepciones. Es crucial para escribir software robusto y fácil de mantener.

Se deben considerar aspectos como:
- Cuándo lanzar una excepción.
- Cómo proporcionar información útil en la excepción.
- Cómo capturar y responder a excepciones específicas.
- Cómo garantizar la liberación de recursos en caso de excepciones.

### 7. Noexcept
La palabra clave `noexcept` indica que una función no lanzará excepciones. Se utiliza para optimizar el rendimiento y la seguridad del código.

**Ejemplo:**
```cpp
void funcionSegura() noexcept {
    // Código garantizado de no lanzar excepciones
}
```
## STL (Standard Template Library)

### 8. Contenedores STL
Los contenedores STL (Standard Template Library) proporcionan una colección de clases de contenedores genéricos. Algunos de los contenedores más comunes incluyen:

1. `std::vector`: para almacenamiento dinámico de arrays.
2. `std::list`: para listas doblemente enlazadas.
3. `std::map`: para almacenar pares clave-valor.
4. `std::set`: para almacenar elementos únicos siguiendo un orden específico.
5. `std::queue`: para la implementación de colas FIFO.

Cada uno tiene usos específicos y se selecciona en base a las necesidades del algoritmo o estructura de datos.

### 9. Iteradores en STL
Los iteradores en la Biblioteca de Plantillas Estándar (STL) de C++ son objetos que permiten recorrer los elementos de un contenedor. Son similares a punteros y proporcionan una forma de acceder a los elementos.

**Ejemplo:**
```cpp
std::vector<int> vec = {1, 2, 3};
for(auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
}
```


### 10. Algoritmos STL
Los algoritmos STL son una serie de funciones predefinidas que realizan operaciones comunes en contenedores. Algunos ejemplos incluyen:

1. `std::sort`: para ordenar elementos.
2. `std::find`: para buscar elementos.
3. `std::accumulate`: para realizar operaciones de suma en un rango.

Estos algoritmos son genéricos y pueden trabajar con diferentes tipos de contenedores STL.

**Ejemplo de std::sort:**
```cpp
std::vector<int> vec = {1, 5, 3};
std::sort(vec.begin(), vec.end()); // Ordena el vector
```

### 11. Algoritmos Personalizados en STL
Se pueden crear algoritmos personalizados que funcionen con contenedores STL, aprovechando la flexibilidad de los iteradores y plantillas.

**Ejemplo de algoritmo personalizado:**
```cpp
template <typename Iterator, typename Func>
void for_each_custom(Iterator begin, Iterator end, Func f) {
    for(auto it = begin; it != end; ++it) {
        f(*it);
    }
}
```
Estos algoritmos permiten una mayor personalización y adaptación a necesidades específicas.

## Expresiones Regulares

### 12. Definición de Expresiones Regulares

Las expresiones regulares son secuencias de caracteres que forman un patrón de búsqueda, utilizadas principalmente para la búsqueda y manipulación de cadenas de texto. Permiten describir patrones complejos y realizar operaciones como búsqueda, reemplazo y validación de forma eficiente y concisa.

**Ejemplo simple:**
```cpp
std::regex patron("[a-zA-Z]+"); // Coincide con cualquier cadena compuesta únicamente por letras
```


### 13. Caracteres Especiales en Expresiones Regulares
Los caracteres especiales en expresiones regulares tienen significados particulares y son fundamentales para definir patrones complejos. Algunos de los más comunes incluyen:

1. `.` - Coincide con cualquier carácter individual.
2. `*` - Indica cero o más ocurrencias del elemento precedente.
3. `+` - Representa una o más ocurrencias del elemento precedente.

Estos caracteres permiten crear patrones flexibles y potentes para coincidir con una amplia variedad de cadenas de texto.

### 14. Uso de Expresiones Regulares en C++

En C++, las expresiones regulares se utilizan mediante la biblioteca `<regex>`. Esta biblioteca proporciona varias clases y funciones para trabajar con expresiones regulares, permitiendo realizar operaciones como búsqueda, reemplazo y validación de cadenas.

**Ejemplo:**
```cpp
std::regex patron("\\d+"); // Coincide con uno o más dígitos
std::string texto = "123 abc";
std::smatch resultados;
if (std::regex_search(texto, resultados, patron)) {
    std::cout << "Número encontrado: " << resultados[0] << std::endl;
}
```


### 15. Validación de Patrones con Expresiones Regulares
Las expresiones regulares son extremadamente útiles para la validación de patrones en cadenas de texto. Permiten verificar si una cadena cumple con un formato específico, como direcciones de correo electrónico, números de teléfono, códigos postales, entre otros.

**Ejemplo de validación de email:**
```cpp
std::regex patronEmail("\\w+@\\w+\\.\\w+");
std::string email = "usuario@example.com";
if (std::regex_match(email, patronEmail)) {
    std::cout << "Email válido" << std::endl;
} else {
    std::cout << "Email inválido" << std::endl;
}
```


