#include "../../include/Softwares/Social.h"
#include "../../include/Software.h"
#include "../../include/User.h"

// Constructor
Social::Social() {
    this->friends = new List();
}

// Destructor
Social::~Social() {

}

// Getters
List* Social::getFriends() {
    return friends;
};

// Setters
void Social::setFriends(List* friends) {
    this->friends = friends;
};

// Methods
void Social::addFriend(User* user) {
    this->friends->add(user);
};

void Social::removeFriend(User* user) {
    this->friends->remove(user);
};

void Social::removeFriend(int index) {
    this->friends->remove(index);
};

void Social::print() {
    cout << "Name: " << this->getName() << endl;
    cout << "Developer: " << this->getDeveloper() << endl;
    cout << "Age Rating: " << this->getAgeRating() << endl;
    cout << "Price: " << this->getPrice() << endl;
    cout << "Type: Social" << endl;
    cout << "Friends: " << endl;
    for (int i = 0; i < this->friends->getSize(); i++) {
        User* user = dynamic_cast<User*>(this->friends->get(i));
        if (user != NULL) {
            cout << " - " << user->getName() << endl;
        }
    }
};