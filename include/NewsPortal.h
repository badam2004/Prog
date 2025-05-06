#ifndef NEWSPORTAL_H
#define NEWSPORTAL_H

#include <map>
#include <vector>
#include <string>
#include "Article.h"
#include "Comment.h"
#include "User.h"

using std::vector, std::map, std::string, std::cerr, std::endl;

class NewsPortal {
private:
    vector<Article> articles;
    vector<Comment> comments;
    vector<User> users;
public:
    void addArticle(const string& title_, const string& content_, const string& author_);
    void addComment(const string& comment_, const string& username_, const string& articleTitle_);
    void addUser(const User& user_) { users.push_back(user_); }

    void listArticles() const;
    void listCommentsForArticle(const string& articleTitle_) const;
    vector<Article> searchByAuthor(const string& author);
    vector<Article> searchByTitle(const string& title);
    void readUsersFromFile(const string& filename);
    bool authenticateUser(const string& username, const string& password);
    User* getUserByName(const std::string& username);
};

#endif // NEWSPORTAL_H
