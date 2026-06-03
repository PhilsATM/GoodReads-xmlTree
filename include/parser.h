#ifndef PARSER_H
#define PARSER_H

#include "node.h"
#include <string>

using std::string;

class Parser {
public:
    // lee un archivo XML y crea un nodo
    static Node* parseXMLFile(const string& filePath);

    // lee todos los XMLs con parseXMLFile y construye el arbol
    static Node* parseAllBooks(const string& booksDirectory);
};

#endif
