#ifndef NEWSPORTAL_H
#define NEWSPORTAL_H

#include <map>
#include <vector>
#include <string>
#include "Article.h"
#include "Comment.h"
#include "User.h"


class NewsPortal {
private:
    std::vector<Article> articles;
    std::vector<Comment> comments;
    std::vector<User> users;
public:
    void addArticle(const std::string& title_, const std::string& content_, const std::string& author_);
    void addComment(const std::string& comment_, const std::string& username_, const std::string& articleTitle_);
    void addUser(const User& user_) { users.push_back(user_); }

    void listArticles() const;
    void listCommentsForArticle(const std::string& articleTitle_) const;
    vector<Article> searchByAuthor(const std::string& author);
    vector<Article> searchByTitle(const std::string& title);
    void readUsersFromFile(const std::string& filename);
    bool authenticateUser(const std::string& username, const std::string& password);
    User* getUserByName(const std::string& username);
};

#endif // NEWSPORTAL_H
