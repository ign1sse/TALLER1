#include <iostream> // Para usar cout y cin
#include <fstream> // Para usar ifstream y ofstream (leer y escribir archivos)
#include <sstream> // Para usar istringstream y getline
#include <vector> // Para usar vector
#include <string> // Para usar string
#include "include/functions.h" // Para usar las funciones propias
#include "include/User.h" // Para usar la clase User
#include "include/Software.h" // Para usar la clase Software
#include "include/Softwares/Browser.h" // Para usar la clase Browser
#include "include/Softwares/Game.h" // Para usar la clase Game
#include "include/Softwares/OfficeAutomation.h" // Para usar la clase OfficeAutomation
#include "include/Softwares/Production.h" // Para usar la clase Production
#include "include/Softwares/Security.h" // Para usar la clase Security
#include "include/Softwares/Social.h" // Para usar la clase Social

using namespace std;

int main() {
    // Creamos las listas de usuarios y softwares
    List* users = new List();
    List* softwares = new List();
    List* myLibrary = new List();
    // Poblamos la base de datos con los datos contenidos en la carpeta "data"
    readUsers(users);
    readSoftwares(softwares);

    // Log
    vector<string> log;

    int option;
    User* currentUser;
    do {
        string user;
        string password;
        currentUser = NULL;
        do {
            cout << "--- Login ---" << endl;
            cout << "User: ";
            cin >> user;
            cout << "Password: ";
            cin >> password;
            // Buscamos el usuario en la lista de usuarios
            for (int i = 0; i < users->getSize(); i++) {
                User* userObj = dynamic_cast<User*>(users->get(i));
                if (userObj != NULL && userObj->getName() == user && userObj->getPassword() == password) {
                    currentUser = userObj;
                    break;
                }
            }
            if (currentUser == NULL) {
                cout << "\nUser or password incorrect" << endl;
                cout << "Try again?" << endl;
                cout << "1) Yes" << endl;
                cout << "2) No, exit program" << endl;
                cout << "Select an option: ";
                cin >> option;
                if (option == 2) {
                    return 0;
                }
            }
        } while (currentUser == NULL);
    
        cout << "\nWelcome, " + user +"!" << endl;
        // Guardamos el log
        log.push_back("The user: "+currentUser->getName()+", logged in");
        do {
            // Primero verificamos si el usuario tiene mensajes nuevos
            for (int i = 0; i < currentUser->getMessages().size(); i++) {
                cout << "\n" + currentUser->getMessages()[i] << endl;
                // El único mensaje que puede recibir un usuario es el de eliminar un software
                // de la lista de softwares del sistema.
                // Si la respuesta del usuario es sí, se elimina el software de su
                // biblioteca.
                // Si la respuesta del usuario es sí, y era la última persona que tenía el software
                // en su biblioteca, entonces se elimina el software del sistema.
                cout << "Do you accept?" << endl;
                cout << "1) Yes" << endl;
                cout << "2) No" << endl;
                cout << "Select an option: ";
                cin >> option;
                if (option == 1) {
                    // Separamos el mensaje en un vector de strings
                    vector<string> data = split(currentUser->getMessages()[i], ':');
                    // Buscamos el software en la lista de softwares
                    for (int j = 0; j < softwares->getSize(); j++) {
                        Software* software = dynamic_cast<Software*>(softwares->get(j));
                        if (software != NULL && software->getName() == trim(data[2])) {
                            // Eliminamos el usuario de la lista de usuarios del software
                            software->removeUser(currentUser);
                            cout << "\nSoftware deleted successfully" << endl;
                            // Guardamos el log
                            log.push_back("The user: "+currentUser->getName()+", deleted the software: "+software->getName());
                            // Si el software no tiene ningún usuario, lo eliminamos del sistema
                            if (software->getUsers()->getSize() == 0) {
                                softwares->remove(software);
                                // Guardamos el log
                                log.push_back("The user: "+currentUser->getName()+", deleted the software: "+software->getName()+
                                ", from the system.");
                            }
                            break;
                        }
                    }
                    // Eliminamos el mensaje de la bandeja de entrada
                    currentUser->removeMessage(i);
                }

            }
            cout << "\n--- Menu ---" << endl;
            cout << "1) My library" << endl;
            cout << "2) List softwares" << endl;
            cout << "3) Logout" << endl;
            if (isAdmin(currentUser)) {
                cout << "4) Add user" << endl;
                cout << "5) Delete user" << endl;
                cout << "6) Edit user" << endl;
                cout << "7) Show log" << endl;
            }
            cout << "Select an option: ";
            cin >> option;

            // Validamos si tiene acceso a las opciones de administrador
            if (option >= 4 && option <= 7 && !isAdmin(currentUser)) {
                cout << "\nYou don't have access to this option" << endl;
                continue;
            }
        
            switch (option) {
                case 1: {
                    // Mostramos los softwares que tiene el usuario
                    cout << "\nMy library:" << endl;
                    for (int i = 0; i < myLibrary->getSize(); i++) {
                        // Usamos casteo dinámico para verificar el tipo de software
                        Software* software = dynamic_cast<Software*>(myLibrary->get(i));
                        if (software != NULL && software->getUsers()->find(currentUser) != -1) {
                            cout << "  " << i + 1 << ") " << software->getName();
                            cout << " (" << software->getAgeRating() << "+)" << endl;
                        }
                    }
                    cout << "0) Back" << endl;
                    // Pedimos al usuario que seleccione un software para eliminar o mostrar información
                    cout << "Select a software: ";
                    int selection;
                    cin >> selection;
                    // Validamos la selección
                    if (selection < 0 || selection > myLibrary->getSize()+1) {
                        cout << "\nInvalid selection" << endl;
                        break;
                    }
                    if (selection == 0) {
                        break;
                    }
                    // Obtenemos el software seleccionado
                    Software* software = dynamic_cast<Software*>(myLibrary->get(selection-1));
                    if (software == NULL) {
                        cout << "\nInvalid selection" << endl;
                        break;
                    }
                    // Validamos que el usuario tenga el software
                    if (software->getUsers()->find(currentUser) == -1) {
                        cout << "\nInvalid selection. Select a software from the list above" << endl;
                        break;
                    }
                    // Le preguntamos al usuario si quiere eliminar el software o mostrar información
                    cout << "\nWhat do you want to do with this software?" << endl;
                    cout << "0) Back" << endl;
                    cout << "1) Delete software" << endl;
                    cout << "2) Show information" << endl;
                    cout << "3) Use software" << endl;
                    cout << "Select an option: ";
                    int option2;
                    cin >> option2;
                    switch (option2) {
                        case 0:
                            break;
                        case 1:
                            // Eliminamos el usuario de la lista de usuarios del software
                            software->removeUser(currentUser);
                            cout << "\nSoftware deleted successfully" << endl;
                            // Guardamos el log
                            log.push_back("The user: "+currentUser->getName()+", deleted the software: "+software->getName());
                            break;
                        case 2: {
                            // Mostramos la información del software
                            cout << "\nSoftware information:" << endl;
                            software->print();
                            // Usamos casteo dinámico para verificar el tipo de software
                            Browser* browser = dynamic_cast<Browser*>(software);
                            if (browser != NULL) {
                                // Mostramos el historial
                                cout << "History: " << endl;
                                // Recorremos el historial desde el más reciente al más antiguo
                                int size = browser->getHistory().size();
                                for (int i = size - 1; i >= 0; i--) {
                                    if (browser->getHistory()[i] != "") {
                                        cout << browser->getHistory()[i] << endl;
                                    }
                                }
                                break;
                            }
                            OfficeAutomation* officeAutomation = dynamic_cast<OfficeAutomation*>(software);
                            if (officeAutomation != NULL) {
                                // Mostramos la cantidad de archivos creados
                                cout << "Files: " << officeAutomation->getFiles() << endl;
                                break;
                            }
                            Social* social = dynamic_cast<Social*>(software);
                            if (social != NULL) {
                                // Mostramos la lista de amigos
                                cout << "Friends: " << endl;
                                for (int i = 0; i < social->getFriends()->getSize(); i++) {
                                    User* user = dynamic_cast<User*>(social->getFriends()->get(i));
                                    if (user != NULL) {
                                        cout << " - " << user->getName() << endl;
                                    }
                                }
                                break;
                            }
                            break;
                        }
                        case 3: {
                            // Usamos casteo dinámico para verificar el tipo de software
                            Browser* browser = dynamic_cast<Browser*>(software);
                            if (browser != NULL) {
                                // Le preguntamos al usuario si quiere agregar una página al historial
                                cout << "\nDo you want to add a page to the history?" << endl;
                                cout << "1) Yes" << endl;
                                cout << "2) No" << endl;
                                cout << "Select an option: ";
                                int option3;
                                cin >> option3;
                                if (option3 == 1) {
                                    // Pedimos la página al usuario
                                    cout << "\nPage: ";
                                    string page;
                                    cin >> page;
                                    // Agregamos la página al historial
                                    browser->addToHistory(page);
                                    cout << "\nPage added successfully" << endl;
                                }
                                break;
                            }
                            OfficeAutomation* officeAutomation = dynamic_cast<OfficeAutomation*>(software);
                            if (officeAutomation != NULL) {
                                // Le preguntamos al usuario si quiere agregar un archivo
                                cout << "\nDo you want to add a file?" << endl;
                                cout << "1) Yes" << endl;
                                cout << "2) No" << endl;
                                cout << "Select an option: ";
                                int option3;
                                cin >> option3;
                                if (option3 == 1) {
                                    // Agregamos un archivo
                                    officeAutomation->addFile();
                                    cout << "\nFile added successfully" << endl;
                                }
                                // Le preguntamos al usuario si quiere eliminar un archivo
                                cout << "\nDo you want to delete a file?" << endl;
                                cout << "1) Yes" << endl;
                                cout << "2) No" << endl;
                                cout << "Select an option: ";
                                cin >> option3;
                                if (option3 == 1) {
                                    // Eliminamos el archivo
                                    officeAutomation->removeFile();
                                    cout << "\nFile deleted successfully" << endl;
                                }
                                break;
                            }
                            Social* social = dynamic_cast<Social*>(software);
                            if (social != NULL) {
                                // Le preguntamos al usuario si quiere agregar un amigo
                                cout << "\nDo you want to add a friend?" << endl;
                                cout << "1) Yes" << endl;
                                cout << "2) No" << endl;
                                cout << "Select an option: ";
                                int option3;
                                cin >> option3;
                                if (option3 == 1) {
                                    // Pedimos el nombre del amigo
                                    cout << "\nFriend: ";
                                    string friendName;
                                    cin >> friendName;
                                    bool found = false;
                                    // Buscamos el amigo en la lista de usuarios
                                    for (int i = 0; i < users->getSize(); i++) {
                                        User* user = dynamic_cast<User*>(users->get(i));
                                        if (user != NULL && user->getName() == friendName) {
                                            found = true;
                                            // Agregamos el amigo a la lista de amigos
                                            social->addFriend(user);
                                            cout << "\nFriend added successfully" << endl;
                                            break;
                                        }
                                    }
                                    // Si no encontramos al amigo, mostramos un mensaje de error
                                    if (!found) {
                                        cout << "\nFriend not found" << endl;
                                    }
                                }
                                break;
                            }
                            // Si el software no tiene ninguna funcionalidad especial, mostramos un mensaje de error
                            cout << "\nThis software doesn't have any special functionality" << endl;
                            // Guardamos el log
                            log.push_back("The user: "+currentUser->getName()+", used the software: "+software->getName());
                            break;
                        }
                        default:
                            cout << "\nInvalid option" << endl;
                            break;
                    }
                    break;
                }
                case 2: {
                    // Mostramos todos los softwares disponibles según tipo el tipo de software
                    cout << "\nSoftwares available:" << endl;
                    cout << "\n-> Browsers <-" << endl;
                    for (int i = 0; i < softwares->getSize(); i++) {
                        // Usamos casteo dinámico para verificar el tipo de software
                        Browser* browser = dynamic_cast<Browser*>(softwares->get(i));
                        if (browser != NULL) {
                            cout << "  " << i + 1 << ") " << browser->getName();
                            cout << " (" << browser->getAgeRating() << "+)" << endl;
                        }
                    }
                    cout << "\n-> Games <-" << endl;
                    for (int i = 0; i < softwares->getSize(); i++) {
                        // Usamos casteo dinámico para verificar el tipo de software
                        Game* game = dynamic_cast<Game*>(softwares->get(i));
                        if (game != NULL) {
                            cout << "  " << i + 1 << ") " << game->getName();
                            cout << " (" << game->getAgeRating() << "+)" << endl;
                        }
                    }
                    cout << "\n-> Office Automation <-" << endl;
                    for (int i = 0; i < softwares->getSize(); i++) {
                        // Usamos casteo dinámico para verificar el tipo de software
                        OfficeAutomation* officeAutomation = dynamic_cast<OfficeAutomation*>(softwares->get(i));
                        if (officeAutomation != NULL) {
                            cout << "  " << i + 1 << ") " << officeAutomation->getName();
                            cout << " (" << officeAutomation->getAgeRating() << "+)" << endl;
                        }
                    }
                    cout << "\n-> Production <-" << endl;
                    for (int i = 0; i < softwares->getSize(); i++) {
                        // Usamos casteo dinámico para verificar el tipo de software
                        Production* production = dynamic_cast<Production*>(softwares->get(i));
                        if (production != NULL) {
                            cout << "  " << i + 1 << ") " << production->getName();
                            cout << " (" << production->getAgeRating() << "+)" << endl;
                        }
                    }
                    cout << "\n-> Security <-" << endl;
                    for (int i = 0; i < softwares->getSize(); i++) {
                        // Usamos casteo dinámico para verificar el tipo de software
                        Security* security = dynamic_cast<Security*>(softwares->get(i));
                        if (security != NULL) {
                            cout << "  " << i + 1 << ") " << security->getName();
                            cout << " (" << security->getAgeRating() << "+)" << endl;
                        }
                    }
                    cout << "\n-> Social <-" << endl;
                    for (int i = 0; i < softwares->getSize(); i++) {
                        // Usamos casteo dinámico para verificar el tipo de software
                        Social* social = dynamic_cast<Social*>(softwares->get(i));
                        if (social != NULL) {
                            cout << "  " << i + 1 << ") " << social->getName();
                            cout << " (" << social->getAgeRating() << "+)" << endl;
                        }
                    }
                    cout << "0) Back" << endl;
                    // Pedimos al usuario que seleccione un software
                    cout << "Select a software: ";
                    int selection;
                    cin >> selection;
                    // Validamos la selección
                    if (selection < 0 || selection > softwares->getSize()+1) {
                        cout << "\nInvalid selection" << endl;
                        break;
                    }
                    if (selection == 0) {
                        break;
                    }
                    // Obtenemos el software seleccionado
                    Software* software = dynamic_cast<Software*>(softwares->get(selection-1));
                    if (software == NULL) {
                        cout << "\nInvalid selection" << endl;
                        break;
                    }
                    // Verificamos si el usuario cumple con los requisitos de edad
                    if (software->getAgeRating() > currentUser->getAge()) {
                        cout << "\nYou are not old enough to use this software" << endl;
                        break;
                    }

                    // Le preguntamos al usuario si quiere agregar el software a su biblioteca,
                    // mostrar su información o borrarlo del sistema
                    cout << "\nSoftware selected: " << software->getName() << endl;
                    cout << "What do you want to do with this software?" << endl;
                    cout << "0) Back" << endl;
                    cout << "1) Add software to my library" << endl;
                    cout << "2) Show information" << endl;
                    cout << "3) Delete software from system" << endl;
                    cout << "Select an option: ";
                    int option2;
                    cin >> option2;

                    switch (option2) {
                        case 0:
                            break;
                        case 1:
                            // Verificamos si el usuario ya tiene el software usando la función
                            // find de la lista
                            if (software->getUsers()->find(currentUser) != -1) {
                                cout << "\nYou already have this software" << endl;
                                break;
                            }
                            // Agregamos el usuario a la lista de usuarios del software
                            software->addUser(currentUser);
                            // Agregamos el software a la biblioteca del usuario
                            myLibrary->add(software);
                            cout << "\nSoftware added successfully" << endl;
                            // Guardamos el log
                            log.push_back("The user: "+currentUser->getName()+", added the software: "+software->getName());
                            break;
                        case 2:
                            // Mostramos la información del software
                            cout << "\nSoftware information:" << endl;
                            software->print();
                            break;
                        case 3:
                            // Eliminamos el software de la lista de softwares

                            // Pero primero verificamos si el software no está en la biblioteca
                            // de ningún otro usuario. De ser así, dejamos un mensaje
                            // en la bandeja de entrada de todos los usuarios que tienen el software
                            // para preguntarles si quieren eliminarlo del sistema.
                            // Si ningun usuario que no sea este mismo tiene el software
                            // entonces lo eliminamos del sistema.

                            // Verificamos si el software está en la biblioteca de algún usuario
                            bool inLibrary = false;
                            for (int i = 0; i < users->getSize(); i++) {
                                User* user = dynamic_cast<User*>(users->get(i));
                                if (user != NULL && user != currentUser && software->getUsers()->find(user) != -1) {
                                    inLibrary = true;
                                    // Le enviamos un mensaje al usuario
                                    if (user != currentUser) {
                                        user->addMessage("The user: "+currentUser->getName()+
                                        ", want to delete this software from the system: "+
                                        software->getName());
                                    }
                                }
                            }

                            // Si el software no está en la biblioteca de ningún usuario
                            // lo eliminamos del sistema
                            if (!inLibrary) {
                                softwares->remove(software);
                                // Si el software está en la biblioteca del usuario, lo eliminamos también
                                if (software->getUsers()->find(currentUser) != -1) {
                                    myLibrary->remove(software);
                                }
                                cout << "\nSoftware deleted successfully" << endl;
                                break;
                            }

                            // Si no, le advertimos al usuario que primero necesita la aprobacion
                            // de los demás usuarios y le preguntamos si quiere eliminarlo de su biblioteca
                            cout << "\nOther users use this software, so you can't delete this directly." << endl;
                            cout << "\nDo you want to delete this software from your library?" << endl;
                            cout << "1) Yes" << endl;
                            cout << "2) No" << endl;
                            cout << "Select an option: ";
                            int option3;
                            cin >> option3;
                            if (option3 == 1) {
                                // Eliminamos el usuario de la lista de usuarios del software
                                software->removeUser(currentUser);
                                // Eliminamos el software de la biblioteca del usuario
                                myLibrary->remove(software);
                                cout << "\nSoftware deleted successfully" << endl;
                            }
                            // Guardamos el log
                            log.push_back("The user: "+currentUser->getName()+
                            ", want to delete this software from the system: "+
                            software->getName());
                            break;
                    }
                    break;
                }
                case 3:
                    // Cerramos sesión
                    cout << "\nLogging out..." << endl;
                    // Guardamos el log
                    log.push_back("The user: "+currentUser->getName()+", logged out");
                    break;
                case 4: {
                    // Agregamos un usuario
                    cout << "\n--- Add user ---" << endl;
                    // Pedimos los datos del usuario
                    cout << "Name: ";
                    string name;
                    cin >> name;
                    cout << "Password: ";
                    string password;
                    cin >> password;
                    cout << "Age: ";
                    int age;
                    cin >> age;
                    cout << "Email: ";
                    string email;
                    cin >> email;
                    cout << "Is admin?" << endl;
                    cout << "1) Yes" << endl;
                    cout << "2) No" << endl;
                    cout << "Select an option: ";
                    int option2;
                    cin >> option2;
                    // Validamos la selección
                    if (option2 < 1 || option2 > 2) {
                        cout << "\nInvalid selection" << endl;
                        break;
                    }
                    bool isAdmin = option2 == 1;
                    // Creamos el usuario
                    User* user = new User();
                    user->setName(name);
                    user->setPassword(password);
                    user->setAge(age);
                    user->setEmail(email);
                    user->setLogAccess(isAdmin);
                    // Agregamos el usuario a la lista de usuarios
                    users->add(user);
                    cout << "\nUser added successfully" << endl;
                    // Guardamos el log
                    log.push_back("The user: "+currentUser->getName()+", added a new user: "+user->getName());
                    break;
                }
                case 5: {
                    // Eliminamos un usuario
                    cout << "\n--- Delete user ---" << endl;
                    // Mostramos la lista de usuarios
                    cout << "Users:" << endl;
                    for (int i = 0; i < users->getSize(); i++) {
                        User* user = dynamic_cast<User*>(users->get(i));
                        if (user != NULL) {
                            cout << "  " << i + 1 << ") " << user->getName() << endl;
                        }
                    }
                    cout << "0) Back" << endl;
                    // Pedimos al usuario que seleccione un usuario para eliminar
                    cout << "Select a user: ";
                    int selection;
                    cin >> selection;
                    // Validamos la selección
                    if (selection < 0 || selection > users->getSize()+1) {
                        cout << "\nInvalid selection" << endl;
                        break;
                    }
                    if (selection == 0) {
                        break;
                    }
                    // Obtenemos el usuario seleccionado
                    User* user = dynamic_cast<User*>(users->get(selection-1));
                    if (user == NULL) {
                        cout << "\nInvalid selection" << endl;
                        break;
                    }
                    // Eliminamos el usuario de la lista de usuarios
                    users->remove(user);
                    cout << "\nUser deleted successfully" << endl;
                    break;
                }
                case 6: {
                    // Editamos un usuario
                    cout << "\n--- Edit user ---" << endl;
                    // Mostramos la lista de usuarios
                    cout << "Users:" << endl;
                    for (int i = 0; i < users->getSize(); i++) {
                        User* user = dynamic_cast<User*>(users->get(i));
                        if (user != NULL) {
                            cout << "  " << i + 1 << ") " << user->getName() << endl;
                        }
                    }
                    cout << "0) Back" << endl;
                    // Pedimos al usuario que seleccione un usuario para editar
                    cout << "Select a user: ";
                    int selection;
                    cin >> selection;
                    // Validamos la selección
                    if (selection < 0 || selection > users->getSize()+1) {
                        cout << "\nInvalid selection" << endl;
                        break;
                    }
                    if (selection == 0) {
                        break;
                    }
                    // Obtenemos el usuario seleccionado
                    User* user = dynamic_cast<User*>(users->get(selection-1));
                    if (user == NULL) {
                        cout << "\nInvalid selection" << endl;
                        break;
                    }
                    // Pedimos los datos del usuario
                    cout << "\nName: ";
                    string name;
                    cin >> name;
                    cout << "Password: ";
                    string password;
                    cin >> password;
                    cout << "Age: ";
                    int age;
                    cin >> age;
                    cout << "Email: ";
                    string email;
                    cin >> email;
                    cout << "Is admin?" << endl;
                    cout << "1) Yes" << endl;
                    cout << "2) No" << endl;
                    cout << "Select an option: ";
                    int option2;
                    cin >> option2;
                    // Validamos la selección
                    if (option2 < 1 || option2 > 2) {
                        cout << "\nInvalid selection" << endl;
                        break;
                    }
                    bool isAdmin = option2 == 1;
                    // Editamos el usuario
                    user->setName(name);
                    user->setPassword(password);
                    user->setAge(age);
                    user->setEmail(email);
                    user->setLogAccess(isAdmin);
                    cout << "\nUser edited successfully" << endl;
                    break;
                }
                case 7:
                    // Mostramos el log
                    cout << "\nLog:" << endl;
                    for (int i = 0; i < log.size(); i++) {
                        cout << log[i] << endl;
                    }
                    break;
                default:
                    cout << "\nInvalid selection" << endl;
                    break;
            }
        } while (option != 3);
    
        cout << "\nExit?" << endl;
        cout << "1) No, log in again" << endl;
        cout << "2) Yes, quit application" << endl;
        cout << "Select an option: ";
        cin >> option;
    } while (option != 2);

    // Guardamos los datos en los archivos
    writeUsers(users);
    writeSoftwares(softwares);

    // Liberamos la memoria de las listas
    delete users;
    delete softwares;
}