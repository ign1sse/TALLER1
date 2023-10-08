#include "../../include/Softwares/Game.h"
#include "../../include/Software.h"

// Constructor
Game::Game() {
    this->genre = "";
}

// Destructor
Game::~Game() {

}

// Getters
string Game::getGenre() {
    return genre;
};

// Setters
void Game::setGenre(string genre) {
    this->genre = genre;
};

// Methods
void Game::print() {
    cout << "Name: " << this->getName() << endl;
    cout << "Developer: " << this->getDeveloper() << endl;
    cout << "Age Rating: " << this->getAgeRating() << endl;
    cout << "Price: " << this->getPrice() << endl;
    cout << "Type: Game" << endl;
    cout << "Genre: " << this->genre << endl;
};