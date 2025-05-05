#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>
#include "Content.h"

class Article : public Content {
    std::string title;
    std::string content;
    std::string author;
    int ArticleId = 0; // inicializálás alapból 0-ra, ha nincs konstruktorban
public:
    Article(std::string t, std::string c, std::string a);

    void display() const override;
    std::string getType() const override;

    std::string getAuthor() const;
    int getArticleId() const;
};

#endif // ARTICLE_H
