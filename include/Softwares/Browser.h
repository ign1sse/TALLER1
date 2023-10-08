#pragma once
#include <iostream>
#include "../Software.h"
#include <vector>

using namespace std;

class Browser: public Software {
    private:
        vector<string> history;
    public:
        Browser(); // Constructor por defecto
        Browser(const Browser& other); // Constructor de copia
        ~Browser(); // Destructor
        Browser& operator= (const Browser& other); // Operador de asignación de copia
        vector<string> getHistory() const;
        void setHistory(vector<string>);
        void addToHistory(string);
        void removeFromHistory(int);
        void clearHistory();
        void print();
};