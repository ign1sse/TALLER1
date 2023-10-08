#include "../../include/Softwares/OfficeAutomation.h"
#include "../../include/Software.h"

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
    // Check if there are files to remove
    if (this->files == 0) {
        cout << "There are no files to remove" << endl;
        return;
    }
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