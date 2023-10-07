#pragma once
#include <iostream>
#include "Object.h"

using namespace std;

class Node {
    private:
        Object* data;
        Node* next;
        Node* prev;
    public:
        Node(Object*);
        ~Node();
        Object* getData();
        Node* getNext();
        Node* getPrev();
        void setData(Object*);
        void setNext(Node*);
        void setPrev(Node*);
};

// Constructor
Node::Node(Object* data) {
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

// Destructor
Node::~Node() {

}

// Getters
Object* Node::getData() {
    return data;
};

Node* Node::getNext() {
    return next;
};

Node* Node::getPrev() {
    return prev;
};

// Setters
void Node::setData(Object* data) {
    this->data = data;
};

void Node::setNext(Node* next) {
    this->next = next;
};

void Node::setPrev(Node* prev) {
    this->prev = prev;
};