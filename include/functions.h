#pragma once
#include <iostream> // Para usar cout y cin
#include <fstream> // Para usar ifstream y ofstream (leer y escribir archivos)
#include <sstream> // Para usar istringstream y getline
#include <vector> // Para usar vector
#include <string> // Para usar string
#include "functions.h" // Para usar las funciones propias
#include "User.h" // Para usar la clase User
#include "Software.h" // Para usar la clase Software
#include "Softwares/Browser.h" // Para usar la clase Browser
#include "Softwares/Game.h" // Para usar la clase Game
#include "Softwares/OfficeAutomation.h" // Para usar la clase OfficeAutomation
#include "Softwares/Production.h" // Para usar la clase Production
#include "Softwares/Security.h" // Para usar la clase Security
#include "Softwares/Social.h" // Para usar la clase Social

using namespace std;

// Función split que separa una cadena por un delimitador
vector<string> split(string s, char delimiter) {
    vector<string> tokens; // Vector que almacena las subcadenas
    string token; // Variable temporal para almacenar cada subcadena
    istringstream tokenStream(s); // Flujo de entrada que lee la cadena
    while (getline(tokenStream, token, delimiter)) { // Mientras haya subcadenas
        tokens.push_back(token); // Agregar la subcadena al vector
    }
    return tokens; // Devolver el vector
}

// Función trim que elimina los espacios en blanco al principio y al final de una cadena
string trim(string s) {
    size_t start = s.find_first_not_of(" "); // Encontrar el primer caracter que no sea un espacio
    size_t end = s.find_last_not_of(" "); // Encontrar el último caracter que no sea un espacio
    return s.substr(start, end - start + 1); // Devolver la subcadena entre el primer y el último caracter no espacios
}

void readUsers(List* users) {
    // Leemos el archivo "users.txt"
    ifstream usersFile;
    usersFile.open("data/users.txt");
    string line;

    while (getline(usersFile, line)) {
        // Separamos la línea en un vector de strings
        vector<string> data = split(line, ','); // Usamos la función split para separar la línea por comas
        // Creamos un nuevo usuario con los datos del vector
        User* user = new User();
        // Asignamos los datos al usuario
        user->setName(trim(data[0]));
        user->setPassword(trim(data[1]));
        user->setAge(stoi(trim(data[2])));
        if (user->getAge() >= 18) {
            user->setEmail(trim(data[3]));
            user->setLogAccess(stoi(trim(data[4])));
        }
        else {
            user->setEmail("");
            user->setLogAccess(0);
        }
        // Agregamos el usuario a la lista de usuarios
        users->add(user);
    }
}

void readSoftwares(List* softwares) {
    // Leemos el archivo "softwares.txt"
    ifstream softwaresFile;
    softwaresFile.open("data/softwares.txt");
    string line;

    // Tipos de software:
    // 1) Browser (1)
    // 2) Game (2)
    // 3) OfficeAutomation (3)
    // 4) Production (4)
    // 5) Security (5)
    // 6) Social (6)

    // Todos los softwares comparten los siguientes atributos:
    // name, developer, ageRating, price
    // Además, en el archivo viene un atributo adicional después del precio que indica el tipo de software
    // Los juegos además tienen el atributo especial "genre"
    // Los softwares de producción además tienen el atributo especial "type"
    // Los softwares de seguridad además tienen el atributo especial "type"

    while (getline(softwaresFile, line)) {
        // Separamos la línea en un vector de strings
        vector<string> data = split(line, ','); // Usamos la función split para separar la línea por comas

        // Usamos polimorfismo para crear un objeto de tipo Software
        Software* software;

        // Dependiendo del tipo de software, creamos un objeto de ese tipo
        switch (stoi(trim(data[4]))) {
            case 1: {
                Browser* browser = new Browser();
                software = browser;
                break;
            }
            case 2: {
                Game* game = new Game();
                game->setGenre(trim(data[5]));
                software = game;
                break;
            }
            case 3: {
                OfficeAutomation* officeAutomation = new OfficeAutomation();
                software = officeAutomation;
                break;
            }
            case 4: {
                Production* production = new Production();
                production->setType(trim(data[5]));
                software = production;
                break;
            }
            case 5: {
                Security* security = new Security();
                security->setType(trim(data[5]));
                software = security;
                break;
            }
            case 6: {
                Social* social = new Social();
                software = social;
                break;
            }
            default:
                break;
        }
        // Asignamos los datos comunes al software
        software->setName(trim(data[0]));
        software->setDeveloper(trim(data[1]));
        software->setAgeRating(stoi(trim(data[2])));
        software->setPrice(stod(trim(data[3])));

        // Agregamos el software a la lista de softwares
        softwares->add(software);
    }
}

void writeUsers(List* users) {
    // Escribimos el archivo "users.txt"
    ofstream usersFile;
    usersFile.open("data/users.txt");

    // Recorremos la lista de usuarios
    for (int i = 0; i < users->getSize(); i++) {
        // Obtenemos el usuario actual
        User* user = (User*) users->get(i);
        // Escribimos los datos del usuario en el archivo
        usersFile << user->getName() << "," << user->getPassword() << "," << user->getAge() << "," << user->getEmail() << "," << user->canAccessLog() << endl;
    }
}

void writeSoftwares(List* softwares) {
    // Escribimos el archivo "softwares.txt"
    ofstream softwaresFile;
    softwaresFile.open("data/softwares.txt");

    // Recorremos la lista de softwares
    for (int i = 0; i < softwares->getSize(); i++) {
        // Obtenemos el software actual
        Software* software = (Software*) softwares->get(i);
        // Escribimos los datos del software en el archivo
        softwaresFile << software->getName() << "," << software->getDeveloper() << "," << software->getAgeRating() << "," << software->getPrice() << ",";
        // Dependiendo del tipo de software, escribimos el tipo de software y sus atributos especiales (de tener)
        // Usamos casteo dinámico para verificar el tipo de software
        Browser* browser = dynamic_cast<Browser*>(software);
        if (browser != NULL) {
            softwaresFile << 1 << endl;
            continue;
        }
        Game* game = dynamic_cast<Game*>(software);
        if (game != NULL) {
            softwaresFile << 2 << "," << game->getGenre() << endl;
            continue;
        }
        OfficeAutomation* officeAutomation = dynamic_cast<OfficeAutomation*>(software);
        if (officeAutomation != NULL) {
            softwaresFile << 3 << endl;
            continue;
        }
        Production* production = dynamic_cast<Production*>(software);
        if (production != NULL) {
            softwaresFile << 4 << "," << production->getType() << endl;
            continue;
        }
        Security* security = dynamic_cast<Security*>(software);
        if (security != NULL) {
            softwaresFile << 5 << "," << security->getType() << endl;
            continue;
        }
        Social* social = dynamic_cast<Social*>(software);
        if (social != NULL) {
            softwaresFile << 6 << endl;
            continue;
        }
    }
}

bool isAdmin(User* user) {
    // Verificamos si el usuario es administrador
    return user->getEmail() != "" && user->canAccessLog() == 1;
}