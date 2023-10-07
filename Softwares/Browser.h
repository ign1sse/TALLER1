#pragma once
#include <iostream>
#include "../Software.h"
#include <vector>

using namespace std;

class Browser: public Software {
    private:
        vector<string> history;
    public:
        Browser();
        ~Browser();
        vector<string> getHistory();
        void setHistory(vector<string>);
        void addToHistory(string);
        void removeFromHistory(int);
        void clearHistory();
        void print();
};

// Constructor
Browser::Browser() {

}

// Destructor
Browser::~Browser() {

}

// Getters
vector<string> Browser::getHistory() {
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