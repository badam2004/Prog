#ifndef ARTICLE_H
#define ARTICLE_H

#include <iostream>
#include <fstream>
#include "Content.h"

class Article : public Content {
    std::string title;
    std::string content;
    std::string author;
    int ArticleId;
public:
    Article(std::string t, std::string c, std::string a): title(std::move(t)), content(std::move(c)), author(std::move(a)) {}

    void display() const override {
        std::cout << "Cikk: " << title << "\nSzerző: " << author << "\n" << content << "\n";
    }

    std::string getType() const override { return "Cikk"; }
    std::string getAuthor() const { return author; }
    int getArticleId() const {return ArticleId; }
};

#endif //ARTICLE_H