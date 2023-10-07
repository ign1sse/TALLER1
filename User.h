#pragma once
#include <iostream>
#include "Object.h"
#include <vector>

using namespace std;

class User: public Object {
    private:
        string name;
        string password;
        int age;
        string email;
        vector<string> messages;
        bool logAccess;
    public:
        User();
        ~User();
        string getName();
        string getPassword();
        int getAge();
        string getEmail();
        vector<string> getMessages();
        bool canAccessLog();
        void setName(string);
        void setPassword(string);
        void setAge(int);
        void setEmail(string);
        void setLogAccess(bool);
        void addMessage(string);
        void removeMessage(int);
        void print();
};

// Constructor
User::User() {
    this->name = "";
    this->password = "";
    this->age = 0;
    this->email = "";
    this->logAccess = false;
};

// Destructor
User::~User() {

};

// Getters
string User::getName() {
    return name;
};

string User::getPassword() {
    return password;
};

int User::getAge() {
    return age;
};

string User::getEmail() {
    return email;
};

vector<string> User::getMessages() {
    return messages;
};

bool User::canAccessLog() {
    return logAccess;
};

// Setters
void User::setName(string name) {
    this->name = name;
};

void User::setPassword(string password) {
    this->password = password;
};

void User::setAge(int age) {
    this->age = age;
};

void User::setEmail(string email) {
    this->email = email;
};

void User::setLogAccess(bool logAccess) {
    this->logAccess = logAccess;
};

// Methods
void User::addMessage(string message) {
    this->messages.push_back(message);
};

void User::removeMessage(int index) {
    this->messages.erase(this->messages.begin() + index);
};

void User::print() {
    cout << "User" << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Password: " << this->getPassword() << endl;
    cout << "Age: " << this->getAge() << endl;
    cout << "Email: " << this->getEmail() << endl;
    cout << "Log Access: " << this->canAccessLog() << endl;
};