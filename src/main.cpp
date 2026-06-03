#include <iostream>
#include "node.h"
#include "parser.h"

using std::cout;
using std::endl;

int main() {
    // parsear los 10k libros en books_xml
    Node* root = Parser::parseAllBooks("books_xml");
    if (root) {

        // prueba a extraer info pa ver si se genero el arbol bien
        if (root->children.size() > 0) {
            Node* firstBook = root->children[0]; // primer libro
            cout << "\n=== Primer libro ===" << endl;
            cout << "Tipo: " << firstBook->type << endl;
            cout << "ID: " << firstBook->id << endl;
            cout << "Titulo: " << firstBook->title << endl;
            cout << "ISBN: " << firstBook->isbn << endl;
            cout << "Ano: " << firstBook->year << endl;
            cout << "Rating: " << firstBook->rating << endl;
            cout << "Paginas: " << firstBook->pages << endl;
            cout << "Libros similares (hijos): " << firstBook->children.size() << endl;

            // primer libro similar del primer libro :3, ahora se saca desde children
            if (firstBook->children.size() > 0) {
                Node* firstSimilar = firstBook->children[0];
                cout << "\n=== Primer libro similar ===" << endl;
                cout << "Tipo: " << firstSimilar->type << endl;
                cout << "ID: " << firstSimilar->id << endl;
                cout << "Titulo: " << firstSimilar->title << endl;
                cout << "ISBN: " << firstSimilar->isbn << endl;
                cout << "Ano: " << firstSimilar->year << endl;
                // etc
            }
        }
    }

    delete root; // liberar toda la memoria
    return 0;
}