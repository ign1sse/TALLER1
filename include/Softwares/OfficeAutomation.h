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