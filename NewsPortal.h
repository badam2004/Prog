/*
#ifndef NEWSPORTAL_H
#define NEWSPORTAL_H

#include <fstream>
#include <map>
#include <vector>

#include "Article.h"
#include "Comment.h"
#include "User.h"


class NewsPortal {
private:
    // Tartalmak tárolása közvetlenül (nem pointerekkel)
    std::vector<Article> articles;
    std::vector<Comment> comments;

    // Cikkek azonosító szerinti kereséshez
    std::map<int, Article*> articleLookup;
    int nextArticleId = 1;

public:
    // Cikk hozzáadása
    int addArticle(const std::string& title, const std::string& content, const std::string& author) {
        int id = nextArticleId++;
        articles.emplace_back(title, content, author);
        articleLookup[id] = &articles.back();
        return id;
    }

    // Komment hozzáadása
    bool addComment(const std::string& text, int userId, int articleId) {
        if (articleLookup.find(articleId) != articleLookup.end()) {
            comments.emplace_back(text, userId, articleId);
            return true;
        }
        return false;
    }
    // Felhasználó hozzáadása
    bool addUser(User alma_user) {
        alma_user.showDashboard();
    };

    // Cikkek listázása
    void listArticles() const {
        for (const auto& article : articles) {
            article.display();
        }
    }

    // Kommentek listázása egy cikkhez
    void listCommentsForArticle(int articleId) const {
        for (const auto& comment : comments) {
            if (comment.getArticleId() == articleId) {
                comment.display();
            }
        }
    }
};

#endif //NEWSPORTAL_H
*/
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
    std::map<int, Article*> articleLookup;
    int nextArticleId = 1;

public:
    int addArticle(const std::string& title, const std::string& content, const std::string& author);
    bool addComment(const std::string& text, int userId, int articleId);
    bool addUser(User alma_user);

    void listArticles() const;
    void listCommentsForArticle(int articleId) const;
};

#endif // NEWSPORTAL_H
