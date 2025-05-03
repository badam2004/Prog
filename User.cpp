#include "User.h"
#include <iostream>

// Konstruktor: string -> Role konvertálás
User::User(std::string name, std::string r) : username(std::move(name)) {
    if (r == "reader") role = READER;
    else if (r == "author") role = AUTHOR;
    else if (r == "admin") role = ADMIN;
    else role = READER; // alapértelmezett érték
}

bool User::canPost() const {
    return role == AUTHOR || role == ADMIN;
}

bool User::canComment() const {
    return true;
}

bool User::canModify() const {
    return role == ADMIN;
}

bool User::canDelete() const {
    return role == ADMIN;
}

void User::showDashboard() const {
    std::string user_role;
    switch (role) {
        case READER:
            user_role = "reader";
            break;
        case AUTHOR:
            user_role = "author";
            break;
        case ADMIN:
            user_role = "admin";
            break;
        default:
            user_role = "Not defined";
            break;
    }
    std::cout << username << " irányítópultja (" << user_role << ")\n";
}
