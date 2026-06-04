#include "treeFuncs.h"
#include <iostream>

using std::cout;
using std::endl;

Tree::Tree() : root(nullptr) {}

Tree::~Tree() {
    if (root) {
        delete root;
    }
}

void Tree::setRoot(Node* node) {
    root = node;
}

//helper recursivo para listar
void listarHelper(Node* node) {
    if (!node) return;
    
    //lista solo si es un libro principal
    if (node->type == "book") {
        cout << node->id << endl;
    }
    
    //llamada recursiva a los hijos
    for (Node* child : node->children) {
        listarHelper(child);
    }
}

void Tree::listar() {
    listarHelper(root);
}

//helper recursivo para borrar
void borrarHelper(Node* node, double r) {
    if (!node) return;
    
    //se itera de atras hacia adelante para eliminar elementos del vector de forma segura
    for (int i = node->children.size() - 1; i >= 0; --i) {
        Node* child = node->children[i];
        
        //se explora primero la profundidad para no perder referencias
        borrarHelper(child, r);
        
        //solo borramos si es un libro principal y su rating promedio es menor a r
        if (child->type == "book" && child->rating <= r) {
            node->children.erase(node->children.begin() + i);
            delete child; //el destructor de Node elimina a sus propios hijos
        }
    }
}

void Tree::borrar_ratings(double r) {
    borrarHelper(root, r);
}

//helper recursivo para precursores
void precursoresHelper(Node* node, vector<int>& result) {
    if (!node) return;
    
    //se valida que sea un libro principal
    if (node->type == "book") {
        bool todos_posteriores = true;
        bool tiene_similares = false;
        if (node->year == 0) {
            todos_posteriores = false; //si no tiene año, no se puede considerar precursor
        }
        else {
            for (Node* child : node->children) {
                if (child->type == "similar_book") { //confirmamos que es un libro similar
                    tiene_similares = true;
                    //si un libro similar se publico en el mismo año o antes (o si no tiene un año especificado), no cumple
                    if (child->year > 0 && child->year <= node->year) {
                        todos_posteriores = false;
                        break;
                    }
                }
            }
        }
        if (tiene_similares && todos_posteriores) {
            result.push_back(node->id);
        }
    }
    
    //continuar recorrido solo en nodos que tienen hijos
    for (Node* child : node->children) {
        if (child->type != "similar_book") { //solo se consideran libros reales para seguir buscando precursores
            precursoresHelper(child, result);
        }
    }
}

vector<int> Tree::precursores() {
    vector<int> result;
    precursoresHelper(root, result);
    return result;
}
