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
            cout << "ID: " << firstBook->id << endl;
            cout << "Titulo: " << firstBook->title << endl;
            cout << "ISBN: " << firstBook->isbn << endl;
            cout << "Ano: " << firstBook->year << endl;
            cout << "Rating: " << firstBook->rating << endl;
            cout << "Paginas: " << firstBook->pages << endl;
            cout << "Libros similares: " << firstBook->similar_books.size() << endl;

            //  primer libro similar del primer libro :3
            if (firstBook->similar_books.size() > 0) {
                cout << "\n=== Primer libro similar ====" << endl;
                cout << "  Titulo: " << firstBook->similar_books[0].title << endl;
                cout << "  ISBN: " << firstBook->similar_books[0].isbn << endl;
                cout << "  Ano: " << firstBook->similar_books[0].year << endl;
                // etc 
            }
        }
    }

    return 0;
}
