#include <stddef.h>
#include "Node.h"

Node::Node(char c, int i) {
    this->symbol = c;
    this->count = i;
}

Node::Node() {
    this->symbol = NULL;
    this->count = 0;
}

char Node::getSymbol() const {
    return symbol;
}

void Node::setSymbol(char symbol) {
    this->symbol = symbol;
}

int Node::getCount() const {
    return count;
}

void Node::setCount(int count) {
    this->count = count;
}