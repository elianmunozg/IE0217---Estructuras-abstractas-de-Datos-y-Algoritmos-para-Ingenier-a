# Definir el compilador
CXX = g++

# Definir las banderas de compilación
CXXFLAGS = -Wall -std=c++11

# Nombre del programa ejecutable
TARGET = mi_programa.exe

# Lista de archivos fuente
SOURCES = main.cpp Agenda.cpp Contacto.cpp

# Generar nombres de archivos objeto
OBJECTS = $(SOURCES:.cpp=.o)

# Regla predeterminada
all: $(TARGET)

# Regla para enlazar el programa ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Regla para compilar cada archivo fuente a un archivo objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) $(OBJECTS)

# Reglas adicionales
.PHONY: all clean