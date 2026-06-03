<<<<<<< HEAD
# GoodReads XML Tree

Proyecto en C++ que parsea archivos XML de Goodreads y construye un árbol de libros usando TinyXML2. Soporta funciones sobre el arbol tales como:
 - listar(): ...
 - borrar_ratings(r): ...
 - precursores(): ...

## Requisitos
- CMake 3.10 o superior.
- Compilador compatible con C++17.

## Compilación con CMake
Desde la raíz del proyecto:

```bash
cmake -S . -B build
cmake --build build
```

## Compilación sin CMake
```
mkdir build
g++ -std=c++17 src/main.cpp src/node.cpp src/parser.cpp external/tinyxml2/tinyxml2.cpp -Iinclude -Iexternal/tinyxml2 -o build/goodreads_tree.exe
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
=======
# GoodReads-xmlTree
>>>>>>> origin/main
