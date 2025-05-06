#include "User.h"
#include <iostream>

User::User(string username_, string password_, int role_){
    username = username_;
    password = password_;
    if (role_ >= READER && role_ <= ADMIN) {
        role = static_cast<Role>(role_);
    } else {
        std::cerr << "Hiba: �rv�nytelen szerepk�d (" << role_ << "), alap�rtelmezettk�nt READER lesz." << std::endl;
        role = READER;
    }
}

void User::setRole(const int role_) {
    if (role_ >= READER && role_ <= ADMIN)
        role = static_cast<Role>(role_);
    else
        std::cerr << "Hiba: �rv�nytelen szerepk�d (" << role_ << ")" << std::endl;
}

// Kiirat�s
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
    std::cout << username << " ir�ny�t�pultja (" << user_role << ")\n";
}
