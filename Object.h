#pragma once
#include <iostream>

using namespace std;

class Object {
    public:
        Object();
        ~Object();
        virtual void print() = 0;
};

// Constructor
Object::Object() {

};

// Destructor
Object::~Object() {

};