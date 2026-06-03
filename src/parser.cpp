#include "parser.h"
#include "tinyxml2.h"
#include <iostream>
#include <filesystem>

using std::cout;
using std::endl;
using tinyxml2::XMLDocument;
using tinyxml2::XMLElement;
namespace fs = std::filesystem;

// lee un archivo XML y crea un nodo
Node* Parser::parseXMLFile(const string& filePath) {
    // carga el archivo
    XMLDocument doc;
    doc.LoadFile(filePath.c_str()); // tuve que usar char por que no me tomaba con el string

    // obtener <book> del XML y crear un su nodo propio
    XMLElement* book = doc.FirstChildElement("GoodreadsResponse")->FirstChildElement("book");
    int id = book->IntAttribute("id");
    Node* node = new Node(id);

    // funciones para extraer datos sin que muera todo xd, 
    auto getTextSafe = [](XMLElement* elem) -> string {
        if (elem && elem->GetText()) return elem->GetText();
        return "";
    };

    auto getIntSafe = [](XMLElement* elem) -> int {
        if (elem) return elem->IntText();
        return 0;
    };

    auto getDoubleSafe = [](XMLElement* elem) -> double {
        if (elem) return elem->DoubleText();
        return 0.0;
    };

    // extraer info del libro con las funciones
    node->title = getTextSafe(book->FirstChildElement("title"));
    node->isbn = getTextSafe(book->FirstChildElement("isbn"));
    node->year = getIntSafe(book->FirstChildElement("publication_year"));
    node->language = getTextSafe(book->FirstChildElement("language_code"));
    node->description = getTextSafe(book->FirstChildElement("description"));
    node->rating = getDoubleSafe(book->FirstChildElement("average_rating"));
    node->pages = getIntSafe(book->FirstChildElement("num_pages"));

    // extraer info de libros similares
    XMLElement* similar = book->FirstChildElement("similar_books");
    if (similar) {
        XMLElement* book_sim = similar->FirstChildElement("book");
        while (book_sim) {
            BookSimilar sim;
            sim.title = getTextSafe(book_sim->FirstChildElement("title"));
            sim.isbn = getTextSafe(book_sim->FirstChildElement("isbn"));
            sim.year = getIntSafe(book_sim->FirstChildElement("publication_year"));
            node->similar_books.push_back(sim);
            book_sim = book_sim->NextSiblingElement("book");
        }
    }

    return node;
}

// // lee todos los XMLs con parseXMLFile y construye el arbol
Node* Parser::parseAllBooks(const string& booksDirectory) {
    Node* root = new Node(0);  // Nodo raiz ficticio

    cout << "Buscando archivos en: " << booksDirectory << endl;

    int count = 0;
    // itera sobre todos los archivos en la carpeta
    for (const auto& entry : fs::directory_iterator(booksDirectory)) {
        if (entry.path().extension() == ".xml") {
            cout << "Cargando: " << entry.path().filename().string() << endl;
            Node* bookNode = parseXMLFile(entry.path().string());
            root->children.push_back(bookNode);
            count++;
        }
    }

    cout << "Total cargados: " << root->children.size() << " libros" << endl;  // debug despues lo hay que sacarlo
    return root;
}

