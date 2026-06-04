# GoodReads XML Tree

Proyecto en C++ que parsea archivos XML de Goodreads y construye un árbol de libros usando TinyXML2. Soporta funciones sobre el arbol tales como:
 - listar(): Listar los IDs de los libros siguiendo un recorrido preorder.
 - borrar_ratings(r): Eliminar del árbol todos los libros con rating promedio menor o igual al parámetro r.
 - precursores(): Listar los IDs de libros que sólo tengan libros similares publicados en años posteriores (Por ejemplo, si un libro con ID 001 fue publicado el año 2000 y todos sus libros similares fueron publicados luego del año 2000, entonces el ID 001 debe ser reportado). Note que para implementar esta función debe usar la información disponibles entre los tags <similar_books> ... </similar_books>, no tiene que buscar un mecanismo para detectar libros similares.

## Requisitos
- Compilador compatible con C++17.
- Preferentemente tener CMake 3.10 o superior.

## Compilación con CMake
Desde la raíz del proyecto:

```bash
cmake -S . -B build
cmake --build build
```

## Compilación sin CMake
```
mkdir build
g++ -I include -I external/tinyxml2 src/*.cpp external/tinyxml2/tinyxml2.cpp -o build/goodreads_tree.exe
```
## Ejecución
En Windows:

```bash
build\goodreads_tree.exe
```

En Linux/macOS:

```bash
./build/goodreads_tree
```

# Colaboradores

- Felipe Alejandro Tilleria Morales — [PhilsATM](https://github.com/PhilsATM)
- Jhostian Matías San Martín Morales — [Jhoossmm](https://github.com/Jhoossmm)
