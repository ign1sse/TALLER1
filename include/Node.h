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