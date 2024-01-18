# Nombre del programa de salida
TARGET = gestion_estudiantes.exe

# Compilador de C++
CC = g++

# Opciones de compilación
CXXFLAGS = -Wall -std=c++11

# Lista de archivos fuente
SOURCES = main.cpp estudiante.cpp

# Lista de archivos objeto generados a partir de los archivos fuente
OBJECTS = $(SOURCES:.cpp=.o)

# Regla para compilar los archivos fuente en archivos objeto
%.o: %.cpp
    $(CC) $(CXXFLAGS) -c $< -o $@

# Regla para compilar el programa a partir de los archivos objeto
$(TARGET): $(OBJECTS)
    $(CC) $(OBJECTS) -o $(TARGET)

# Regla para limpiar los archivos generados
clean:
    del $(TARGET) $(OBJECTS)
