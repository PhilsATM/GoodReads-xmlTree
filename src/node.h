#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

using std::string;
using std::vector;

struct BookSimilar {
    string title;
    string isbn;
    int year;
};

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


