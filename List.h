#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class List {
    private:
        Node* head;
        Node* tail;
        int size;
    public:
        List();
        ~List();
        void add(Object*);
        void remove(int);
        void remove(Object*);
        Object* get(int);
        int getSize();
        int find(Object*);
};

// Constructor
List::List() {
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}

// Destructor
List::~List() {

}

// Methods
void List::add(Object* data) {
    Node* node = new Node(data);
    if (this->head == NULL) {
        this->head = node;
        this->tail = node;
    } else {
        this->tail->setNext(node);
        node->setPrev(this->tail);
        this->tail = node;
    }
    this->size++;
};

void List::remove(int index) {
    if (index >= 0 && index < this->size) {
        Node* node = this->head;
        if (index == 0) {
            this->head = node->getNext();
            if (this->head) this->head->setPrev(NULL); // Solo llama a setPrev si head no es nulo
        } else if (index == this->size - 1) {
            node = this->tail;
            this->tail = node->getPrev();
            this->tail->setNext(NULL);
        } else {
            for (int i = 0; i < index; i++) {
                node = node->getNext();
            }
            node->getPrev()->setNext(node->getNext());
            node->getNext()->setPrev(node->getPrev());
        }
        delete node;
        this->size--;
    }
};

void List::remove(Object* data) {
    Node* node = this->head;
    int index = 0;
    while (node != NULL) {
        if (node->getData() == data) {
            this->remove(index);
            break;
        }
        node = node->getNext();
        index++;
    }
};

Object* List::get(int index) {
    if (index >= 0 && index < this->size) {
        Node* node = this->head;
        for (int i = 0; i < index; i++) {
            node = node->getNext();
        }
        return node->getData();
    }
    return NULL;
};

int List::getSize() {
    return this->size;
};

// Busca un objeto en la lista. Si lo encuentra retorna su indice, y si no lo encuentra retorna -1
int List::find(Object* data) {
    Node* node = this->head;
    int index = 0;
    while (node != NULL) {
        if (node->getData() == data) {
            return index;
        }
        node = node->getNext();
        index++;
    }
    return -1;
};