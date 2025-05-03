/*
#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>

enum Role {
    READER, //0
    AUTHOR, //1
    ADMIN   //2
};

class User {
    std::string username;
    Role role; // "reader", "author", "admin"
public:
    User(std::string name, std::string r) : username(std::move(name)), role(std::move(r)) {}

    bool canPost() const { return role == Role::AUTHOR || role == Role::ADMIN; }
    bool canComment() const { return true; }
    bool canModify() const { return role == Role::ADMIN; ;}
    bool canDelete() const { return role == Role::ADMIN; ;}
    void showDashboard() const {
        std::string user_role;
        switch (role) {
            case Role::READER:
                user_role = "reader";
            break;
            case Role::AUTHOR:
                user_role = "author";
            break;
            case Role::ADMIN:
                user_role = "admin";
            break;

            default:
                user_role = "Not defined";
            break;
        }
        std::cout << username << " irányítópultja (" << user_role << ")\n";
    }
};

#endif //USER_H
*/
/////////////////////////////////////
#ifndef USER_H
#define USER_H

#include <string>

enum Role {
    READER, // 0
    AUTHOR, // 1
    ADMIN   // 2
};

class User {
    std::string username;
    Role role;
public:
    User(std::string name, std::string r);

    bool canPost() const;
    bool canComment() const;
    bool canModify() const;
    bool canDelete() const;

    void showDashboard() const;
};

#endif // USER_H
