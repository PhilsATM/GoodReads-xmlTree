#include "../include/node.h"

// constructor que inicializa los valores por defecto
Node::Node(int id) : id(id), year(0), pages(0), rating(0.0) {}

// libera la memoria
Node::~Node() {
    for (Node* child : children) {
        delete child;
    }
    children.clear();
    similar_books.clear();
}
