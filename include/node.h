#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

using std::string;
using std::vector;

// info de los libros similares 
struct BookSimilar {
    string title;
    string isbn;
    int year;
};

// nodo para los libros en el arbol con sus campos de informacion
class Node {
public:
    int id;              
    string title;       
    string isbn;         
    int year;            
    string language;     
    string description;  
    double rating;      
    int pages;           
    vector<BookSimilar> similar_books;  
    vector<Node*> children;            

    Node(int id = 0);
    ~Node();
};

#endif


