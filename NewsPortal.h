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
    std::map<int, Article*> articleLookup;
    int nextArticleId = 1;

public:
    int addArticle(const std::string& title, const std::string& content, const std::string& author);
    bool addComment(const std::string& text, int userId, int articleId);
    int addUser(User alma_user);

    void listArticles() const;
    void listCommentsForArticle(int articleId) const;
    std::vector<Article> searchByAuthor(const std::string& pelda);
};

#endif // NEWSPORTAL_H
