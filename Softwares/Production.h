#pragma once
#include <iostream>
#include "../Software.h"

using namespace std;

class Production: public Software {
    private:
        string type; // Video, Audio, Image, Streaming
    public:
        Production();
        ~Production();
        string getType();
        void setType(string);
        void print();
};

// Constructor
Production::Production() {
    this->type = "";
}

// Destructor
Production::~Production() {

}

// Getters
string Production::getType() {
    return type;
};

// Setters
void Production::setType(string type) {
    this->type = type;
};

// Methods
void Production::print() {
    cout << "Name: " << this->getName() << endl;
    cout << "Developer: " << this->getDeveloper() << endl;
    cout << "Age Rating: " << this->getAgeRating() << endl;
    cout << "Price: " << this->getPrice() << endl;
    cout << "Type: Production" << endl;
    cout << "Production type: " << this->type << endl;
};