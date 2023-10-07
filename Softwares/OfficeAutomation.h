#pragma once
#include <iostream>
#include "../Software.h"

using namespace std;

class OfficeAutomation: public Software {
    private:
        int files; // Number of files created by the users
    public:
        OfficeAutomation();
        ~OfficeAutomation();
        int getFiles();
        void setFiles(int);
        void addFile();
        void removeFile();
        void print();
};

// Constructor
OfficeAutomation::OfficeAutomation() {
    this->files = 0;
}

// Destructor
OfficeAutomation::~OfficeAutomation() {

}

// Getters
int OfficeAutomation::getFiles() {
    return files;
};

// Setters
void OfficeAutomation::setFiles(int files) {
    this->files = files;
};

// Methods
void OfficeAutomation::addFile() {
    this->files++;
};

void OfficeAutomation::removeFile() {
    this->files--;
};

void OfficeAutomation::print() {
    cout << "Name: " << this->getName() << endl;
    cout << "Developer: " << this->getDeveloper() << endl;
    cout << "Age Rating: " << this->getAgeRating() << endl;
    cout << "Price: " << this->getPrice() << endl;
    cout << "Type: OfficeAutomation" << endl;
    cout << "Name: " << this->getName() << endl;
};