# Makefile

CXX = g++
CXXFLAGS = -Wall -std=c++11

# Define los nombres de tus archivos fuente y de cabecera aquí
SOURCES = main.cpp OperacionesBasicas.cpp
HEADERS = Matriz.hpp OperacionesBasicas.hpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = main.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
.PHONY: all clean
