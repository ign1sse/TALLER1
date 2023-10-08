#pragma once
#include "Object.h"
#include <iostream>
#include <vector>
#include <string>

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