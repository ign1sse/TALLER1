#pragma once
#include <iostream>
#include "../Software.h"

using namespace std;

class Game: public Software {
    private:
        string genre;
    public:
        Game();
        ~Game();
        string getGenre();
        void setGenre(string);
        void print();
};