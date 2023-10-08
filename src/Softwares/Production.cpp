#include "../../include/Softwares/Production.h"
#include "../../include/Software.h"

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