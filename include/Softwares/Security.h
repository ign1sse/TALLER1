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