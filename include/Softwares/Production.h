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