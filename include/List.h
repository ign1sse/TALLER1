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