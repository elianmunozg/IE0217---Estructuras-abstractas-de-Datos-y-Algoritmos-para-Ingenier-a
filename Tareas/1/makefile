# Detectar el sistema operativo usando variables de entorno de Windows
ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell uname -s)
endif

# Configuraciones específicas del OS
ifeq ($(detected_OS),Windows)
    CC=g++
    RM=del /Q /F
    EXECUTABLE=adivina.exe
else
    CC=g++
    RM=rm -f
    EXECUTABLE=adivina.x
endif

# Opciones de compilación
CFLAGS=-c -Wall

# Directorio de los archivos fuente
SRCDIR=src

# Targets
all: build run

build: $(SRCDIR)/main.o $(SRCDIR)/game.o
	$(CC) $(SRCDIR)/main.o $(SRCDIR)/game.o -o $(EXECUTABLE)

$(SRCDIR)/main.o: $(SRCDIR)/main.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/main.cpp -o $(SRCDIR)/main.o

$(SRCDIR)/game.o: $(SRCDIR)/game.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/game.cpp -o $(SRCDIR)/game.o

clean:
	$(RM) $(SRCDIR)/*.o $(EXECUTABLE)

run:
	./$(EXECUTABLE)
