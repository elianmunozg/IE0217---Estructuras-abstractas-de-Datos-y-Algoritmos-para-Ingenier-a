# Detectar el sistema operativo usando variables de entorno de Windows
ifeq ($(OS),Windows_NT)
    detected_OS := Windows
    RM = del /Q
    EXT = .exe
    FIX_PATH = $(subst /,\,$1)
else
    detected_OS := $(shell uname -s)
    RM = rm -f
    EXT = .out
    FIX_PATH = $1
endif

# Nombre del ejecutable
EXECUTABLE := programa$(EXT)

# Compilador
CC := g++

# Flags de compilación
CFLAGS := -w

# Directorio de los archivos fuente
SRCDIR := src

# Directorio de los archivos objeto
OBJDIR := obj

# Archivo fuente principal
MAIN := $(SRCDIR)/main.cpp

# Target por defecto
all: build

# Regla para construir el ejecutable
build: $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) -o $(EXECUTABLE)

# Regla para limpiar archivos objeto y ejecutable
clean:
	$(RM) $(call FIX_PATH,$(EXECUTABLE))

# Regla para ejecutar el programa
run: 
	$(call FIX_PATH,./$(EXECUTABLE))

.PHONY: all build clean run
