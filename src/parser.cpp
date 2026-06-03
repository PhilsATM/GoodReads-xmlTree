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
    if (doc.LoadFile(filePath.c_str()) != tinyxml2::XML_SUCCESS) {
        return nullptr;
    }

    // obtener <book> del XML y crear un su nodo propio
    XMLElement* response = doc.FirstChildElement("GoodreadsResponse");
    if (!response) return nullptr;

    XMLElement* book = response->FirstChildElement("book");
    if (!book) return nullptr;

    // funciones para extraer datos sin que muera todo xd
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

    Node* node = new Node(book->IntAttribute("id"), "book");

    // extraer info del libro con las funciones
    node->title = getTextSafe(book->FirstChildElement("title"));
    node->isbn = getTextSafe(book->FirstChildElement("isbn"));
    node->year = getIntSafe(book->FirstChildElement("publication_year"));
    node->language = getTextSafe(book->FirstChildElement("language_code"));
    node->description = getTextSafe(book->FirstChildElement("description"));
    node->rating = getDoubleSafe(book->FirstChildElement("average_rating"));
    node->pages = getIntSafe(book->FirstChildElement("num_pages"));

    // extraer info de libros similares, ahora en vez de guardarlos en un vector aparte son hijos del <book>
    XMLElement* similar = book->FirstChildElement("similar_books");
    if (similar) {
        XMLElement* bookSim = similar->FirstChildElement("book");
        while (bookSim) {
            // crea nodo hijo para cada libro similar
            Node* simNode = new Node(bookSim->IntAttribute("id"), "similar_book");
            simNode->title = getTextSafe(bookSim->FirstChildElement("title"));
            simNode->isbn = getTextSafe(bookSim->FirstChildElement("isbn"));
            simNode->year = getIntSafe(bookSim->FirstChildElement("publication_year"));

            node->children.push_back(simNode);
            bookSim = bookSim->NextSiblingElement("book");
        }
    }

    return node;
}

// lee todos los XMLs con parseXMLFile y construye el arbol
Node* Parser::parseAllBooks(const string& booksDirectory) {
    Node* root = new Node(0, "root"); // nodo raiz ficticio

    cout << "Buscando archivos en: " << booksDirectory << endl;

    // itera sobre todos los archivos en la carpeta
    for (const auto& entry : fs::directory_iterator(booksDirectory)) {
        if (entry.path().extension() == ".xml") {
            cout << "Cargando " << entry.path().filename().string() << endl;

            Node* bookNode = parseXMLFile(entry.path().string());
            if (bookNode) {
                root->children.push_back(bookNode);
            }
        }
    }

    cout << "Total cargados: " << root->children.size() << " libros" << endl;
    // debug despues lo hay que sacar
    return root;
}