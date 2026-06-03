#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <vector>

using std::vector;

class Tree {
private:
    Node* root;  // raiz del arbol

public:
    Tree();
    ~Tree();
    void setRoot(Node* node);  // asigna un nodo que le pasemos como el nodo root

    // lista IDs de libros en preorder
    void listar();

    // elimina libros con rating menor o igual a r
    void borrar_ratings(double r);

    // encuentra libros precursores
    vector<int> precursores();
};

#endif
