#include "Article.h"
#include <iostream>

// Konstruktor
Article::Article(std::string t, std::string c, std::string a)
    : title(std::move(t)), content(std::move(c)), author(std::move(a)) {}

// Megjelenítés
void Article::display() const {
    std::cout << "Cikk: " << title << "\nSzerzõ: " << author << "\n" << content << "\n";
}

// Típus lekérdezés
std::string Article::getType() const {
    return "Cikk";
}

// Szerzõ lekérdezés
std::string Article::getAuthor() const {
    return author;
}

// Cikk azonosító lekérdezés
int Article::getArticleId() const {
    return ArticleId;
}
