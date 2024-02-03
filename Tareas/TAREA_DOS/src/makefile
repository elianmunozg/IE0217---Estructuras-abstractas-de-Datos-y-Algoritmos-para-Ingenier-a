# Definir el compilador
CXX=g++

# Definir las banderas de compilación
CXXFLAGS=-std=c++11 -Wall

# Enumerar los archivos objeto basados en los archivos fuente
OBJ=main.o Libro.o MaterialAudiovisual.o MaterialLectura.o Noticia.o Pelicula.o Podcast.o

# Definir el nombre del ejecutable
EXEC=programa

# Regla por defecto
all: $(EXEC)

# Regla para construir el ejecutable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Reglas para construir los archivos objeto
%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $<

# Limpiar archivos objeto y ejecutable
clean:
	rm -f $(OBJ) $(EXEC)

# Indicar al Makefile que 'all' y 'clean' no son archivos
.PHONY: all clean
