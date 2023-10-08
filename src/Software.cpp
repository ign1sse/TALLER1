#include "../include/Software.h"
#include "../include/List.h"
#include "../include/User.h"

// Constructor
Software::Software() {
    this->name = "";
    this->developer = "";
    this->ageRating = 0;
    this->users = new List();
    this->price = 0.0;
}

// Constructor de copia
Software::Software (const Software& other) {
    // Copiamos los atributos del otro objeto
    this->name = other.getName();
    this->developer = other.getDeveloper();
    this->ageRating = other.getAgeRating();
    this->price = other.getPrice();
    this->setUsers(other.getUsers());
}

// Operador de asignación de copia
Software& Software::operator= (const Software& other) {
    // Verificamos que no sea el mismo objeto
    if (this != &other) {
        // Copiamos los atributos del otro objeto
        this->name = other.getName();
        this->developer = other.getDeveloper();
        this->ageRating = other.getAgeRating();
        this->price = other.getPrice();
        this->setUsers(other.getUsers());
    }
    // Devolvemos una referencia al objeto actual
    return *this;
}


// Destructor
Software::~Software() {

}

// Getters
string Software::getName() const {
    return name;
};

string Software::getDeveloper() const {
    return developer;
};

int Software::getAgeRating() const {
    return ageRating;
};

List* Software::getUsers() const {
    return users;
};

double Software::getPrice() const {
    return price;
};

// Setters
void Software::setName(string name) {
    this->name = name;
};

void Software::setDeveloper(string developer) {
    this->developer = developer;
};

void Software::setAgeRating(int ageRating) {
    this->ageRating = ageRating;
};

void Software::setUsers(List* users) {
    this->users = users;
};

void Software::setPrice(double price) {
    this->price = price;
};

// Methods
void Software::addUser(User* user) {
    this->users->add(user);
};

void Software::removeUser(User* user) {
    this->users->remove(user);
};

void Software::removeUser(int index) {
    this->users->remove(index);
};