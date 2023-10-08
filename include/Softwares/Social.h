#pragma once
#include <iostream>
#include "../Software.h"
#include "../User.h"

using namespace std;

class Social: public Software {
    private:
        List* friends; // List of users
    public:
        Social();
        ~Social();
        List* getFriends();
        void setFriends(List*);
        void addFriend(User*);
        void removeFriend(User*);
        void removeFriend(int);
        void print();
};