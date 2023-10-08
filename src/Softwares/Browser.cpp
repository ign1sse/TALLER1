#include "../../include/Softwares/Browser.h"
#include "../../include/Software.h"

// Constructor
Browser::Browser() {

}

// Constructor de copia
Browser::Browser (const Browser& other) : Software (other) { // Llamamos al constructor de copia de la clase base
    // Copiamos solo el atributo propio de la clase derivada
    this->setHistory(other.getHistory());
}

// Operador de asignación de copia
Browser& Browser::operator= (const Browser& other) {
    // Verificamos que no sea el mismo objeto
    if (this != &other) {
        // Llamamos al operador de asignación de copia de la clase base
        Software::operator= (other);
        // Copiamos solo el atributo propio de la clase derivada
        this->setHistory(other.getHistory());
    }
    // Devolvemos una referencia al objeto actual
    return *this;
}

// Destructor
Browser::~Browser() {

}

// Getters
vector<string> Browser::getHistory() const {
    return history;
};

// Setters
void Browser::setHistory(vector<string> history) {
    this->history = history;
};

// Methods
void Browser::addToHistory(string url) {
    this->history.push_back(url);
};

void Browser::removeFromHistory(int index) {
    this->history.erase(this->history.begin() + index);
};

void Browser::clearHistory() {
    this->history.clear();
};

void Browser::print() {
    cout << "Name: " << this->getName() << endl;
    cout << "Developer: " << this->getDeveloper() << endl;
    cout << "Age Rating: " << this->getAgeRating() << endl;
    cout << "Price: " << this->getPrice() << endl;
    cout << "Type: Browser" << endl;
};