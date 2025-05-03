#include "NewsPortal.h"
#include <iostream>

// Cikk hozzáadása
int NewsPortal::addArticle(const std::string& title, const std::string& content, const std::string& author) {
    int id = nextArticleId++;
    articles.emplace_back(title, content, author);
    articleLookup[id] = &articles.back();
    return id;
}

// Komment hozzáadása
bool NewsPortal::addComment(const std::string& text, int userId, int articleId) {
    if (articleLookup.find(articleId) != articleLookup.end()) {
        comments.emplace_back(text, userId, articleId);
        return true;
    }
    return false;
}

// Felhasználó hozzáadása (egyszerűsített példa)
bool NewsPortal::addUser(User alma_user) {
    alma_user.showDashboard(); // Ez inkább demonstráció, valódi felhasználókezeléshez tárolni is kellene
    return true;
}

// Cikkek listázása
void NewsPortal::listArticles() const {
    for (const auto& article : articles) {
        article.display();
    }
}

// Kommentek listázása egy adott cikkhez
void NewsPortal::listCommentsForArticle(int articleId) const {
    for (const auto& comment : comments) {
        if (comment.getArticleId() == articleId) {
            comment.display();
        }
    }
}
