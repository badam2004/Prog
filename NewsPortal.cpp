#include "NewsPortal.h"
#include <iostream>

// Cikk hozzáadása
int NewsPortal::addArticle(const std::string& title, const std::string& content, const std::string& author) {
    Article tmp(title, content, author);
    int id = nextArticleId++;
    articles.push_back(tmp);
    articleLookup[id] = &articles.back();
    return id;
}

// Komment hozzáadása
bool NewsPortal::addComment(const std::string& text, int userId, int articleId) {
    if()
    Comment tmp(text, userId, articleId);
    if (articleLookup.find(articleId) != articleLookup.end()) {
        comments.push_back(tmp);
        return true;
    }
    return false;
}

// Felhasználó hozzáadása (egyszerûsített példa)
bool NewsPortal::addUser(User alma_user) {

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
            std::cout << comment << "\n" << std::endl;
        }
    }
}

std::vector<Article> NewsPortal::searchByAuthor(const std::string& pelda){
    std::vector<Article> v1;
    for(int i = 0; i < this->articles.size(); i ++){
        if(this->articles[i].getAuthor() == pelda){
            v1.push_back(articles[i]);
        }
    }
};
