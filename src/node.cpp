#include "node.h"

// constructor que inicializa los valores por defecto
Node::Node(int id, const string& type)
    : id(id), type(type), year(0), language(""), description(""), rating(0.0), pages(0) {}

// libera la memoria
Node::~Node() {
    for (Node* child : children) {
        delete child;
    }
    children.clear();
}