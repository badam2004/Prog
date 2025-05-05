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
