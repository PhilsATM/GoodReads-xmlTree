#ifndef PARSER_H
#define PARSER_H

#include "node.h"
#include <string>

class Parser {
public:
    static Node* parseAllBooks(const string& booksDirectory);
    static Node* parseXMLFile(const string& filePath);
};

#endif
