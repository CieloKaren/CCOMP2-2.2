# Lista de archivos fuente
SOURCES = main.cpp chessGame.cpp board.cpp piece.cpp

# Lista de archivos de encabezado
HEADERS = chessGame.h board.h piece.h

# Nombre del ejecutable
EXECUTABLE = main

# Regla para compilar los archivos fuente a objetos
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@ -I"C:\SFML-2.6.0\include" -DSFML_STATIC

# Regla para construir el ejecutable
$(EXECUTABLE): $(SOURCES:.cpp=.o)
	g++ $^ -o $@ -L"C:\SFML-2.6.0\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

# Regla para limpiar archivos objeto
clean:
	rm -f *.o $(EXECUTABLE)
