#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

using std::string;
using std::vector;

// nodo para los libros en el arbol con sus campos de informacion
class Node {
public:
    int id;
    string type; // tipo de nodo pa cachar si es root, book o similar_book
    string title;
    string isbn;
    int year;
    string language;
    string description;
    double rating;
    int pages;
    vector<Node*> children; // ahora los hijos son nodos igual

    Node(int id = 0, const string& type = "book");
    ~Node(); //destructor
};

#endif