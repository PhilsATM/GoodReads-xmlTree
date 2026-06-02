#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <vector>

using std::vector;

class Tree {
private:
    Node* root;

public:
    Tree();
    ~Tree();
    void setRoot(Node* node);

    void listar();
    void borrar_ratings(double r);
    vector<int> precursores();
};

#endif
