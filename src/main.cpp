#include <iostream>
#include "node.h"
#include "parser.h"
#include "treeFuncs.h"

using std::cout;
using std::endl;

int main() {
    cout << "=== Cargando Dataset ===" << endl;
    Node* rootNode = Parser::parseAllBooks("books_xml");
    
    if (rootNode) {
        Tree* arbolLibros = new Tree();
        arbolLibros->setRoot(rootNode);

        // Prueba listado preorder 
        // (Imprimimos aviso para que la consola no colapse con los 10,000 IDs)
        cout << "\n=== Prueba 1: Listar (Preorder) ===" << endl;
        cout << "Iniciando listado de IDs..." << endl;
        arbolLibros->listar(); // Descomenta esta línea para imprimir todos los IDs reales.

        // Prueba de precursores
        cout << "\n=== Prueba 2: Precursores ===" << endl;
        vector<int> prec = arbolLibros->precursores();
        cout << "Se encontraron " << prec.size() << " libros precursores." << endl;
        
        // Prueba de borrar_ratings
        double ratingCorte = 4.2;
        cout << "\n=== Prueba 3: Borrar Ratings <= " << ratingCorte << " ===" << endl;
        size_t cantidadAntes = rootNode->children.size();
        cout << "Cantidad de hijos en raiz antes de borrar: " << cantidadAntes << endl;
        
        arbolLibros->borrar_ratings(ratingCorte);
        
        size_t cantidadDespues = rootNode->children.size();
        cout << "Cantidad de hijos en raiz despues de borrar: " << cantidadDespues << endl;
        cout << "Se eliminaron " << (cantidadAntes - cantidadDespues) << " nodos de primer nivel." << endl;

        delete arbolLibros; // Libera toda la memoria 
    } else {
        cout << "Error al cargar los archivos XML." << endl;
    }

    return 0;
}