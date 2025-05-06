#ifndef USER_H
#define USER_H


#include <string>

using std::string;

enum Role {
    READER, // 0
    AUTHOR, // 1
    ADMIN   // 2
};

class User {
    string username; //Neve
    string password;       //Jelszó
    Role role;            //Engedélye
public:
    //Konstruktor
    User(string username_, string password_) : username(username_), password(password_), role(READER) {}
    User(string username_, string password_, Role role_) : username(username_), password(password_), role(role_) {}
    User(string username_, string password_, int role_);

    // Getterek
    string getUsername() const { return username; }
    string getPassword() const { return password; }
    int getRole() const { return role; }
    // Role getRole() const {return role; }
    // Setterek
    void setUsername(const string& username_) { username = username_; }
    void setPassword(const string& password_) { password = password_; }
    void setRole(const int role_);

    //Engedélyek
    bool canPost() const { return role == AUTHOR || role == ADMIN; }
    bool canComment() const { return true; }
    bool canModify() const { return role == ADMIN; }
    bool canDelete() const { return role == ADMIN; }

    //Az összes kiiratása
    void showDashboard() const;
};

#endif // USER_H
