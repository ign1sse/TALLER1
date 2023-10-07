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
        Software();
        ~Software();
        string getName();
        string getDeveloper();
        int getAgeRating();
        List* getUsers();
        double getPrice();
        void setName(string);
        void setDeveloper(string);
        void setAgeRating(int);
        void setUsers(List*);
        void setPrice(double);
        void addUser(User*);
        void removeUser(User*);
        void removeUser(int);
        virtual void print() = 0;
};

// Constructor
Software::Software() {
    this->name = "";
    this->developer = "";
    this->ageRating = 0;
    this->users = new List();
    this->price = 0.0;
}

// Destructor
Software::~Software() {

}

// Getters
string Software::getName() {
    return name;
};

string Software::getDeveloper() {
    return developer;
};

int Software::getAgeRating() {
    return ageRating;
};

List* Software::getUsers() {
    return users;
};

double Software::getPrice() {
    return price;
};

// Setters
void Software::setName(string name) {
    this->name = name;
};

void Software::setDeveloper(string developer) {
    this->developer = developer;
};

void Software::setAgeRating(int ageRating) {
    this->ageRating = ageRating;
};

void Software::setUsers(List* users) {
    this->users = users;
};

void Software::setPrice(double price) {
    this->price = price;
};

// Methods
void Software::addUser(User* user) {
    this->users->add(user);
};

void Software::removeUser(User* user) {
    this->users->remove(user);
};

void Software::removeUser(int index) {
    this->users->remove(index);
};