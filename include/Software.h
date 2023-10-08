#pragma once
#include <iostream>
#include "List.h"
#include "User.h"

using namespace std;

class Software: public Object {
    private:
        string name;
        string developer;
        int ageRating;
        List* users;
        double price;
    public:
        // Constructor por defecto
        Software();
        // Constructor de copia
        Software(const Software& other);
        // Operador de asignación de copia
        Software& operator= (const Software& other);
        // Destructor
        ~Software();
        // Getters
        string getName() const;
        string getDeveloper() const;
        int getAgeRating() const;
        List* getUsers() const;
        double getPrice() const;
        // Setters
        void setName(string);
        void setDeveloper(string);
        void setAgeRating(int);
        void setUsers(List*);
        void setPrice(double);
        // Methods
        void addUser(User*);
        void removeUser(User*);
        void removeUser(int);
        virtual void print() = 0;
};