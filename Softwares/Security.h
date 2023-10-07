#pragma once
#include <iostream>
#include "../Software.h"

using namespace std;

class Security: public Software {
    private:
        string type; // Tipo de malware: Ransomware, Spyware, Botnets, Rootkits, Gusanos, Troyanos
    public:
        Security();
        ~Security();
        string getType();
        void setType(string);
        void print();
};

// Constructor
Security::Security() {
    this->type = "";
}

// Destructor
Security::~Security() {

}

// Getters
string Security::getType() {
    return type;
};

// Setters
void Security::setType(string type) {
    this->type = type;
};

// Methods
void Security::print() {
    cout << "Name: " << this->getName() << endl;
    cout << "Developer: " << this->getDeveloper() << endl;
    cout << "Age Rating: " << this->getAgeRating() << endl;
    cout << "Price: " << this->getPrice() << endl;
    cout << "Type: Security" << endl;
    cout << "Security type: " << this->type << endl;
};