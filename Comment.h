#ifndef COMMENT_H
#define COMMENT_H

#include <iostream>
#include <fstream>
#include "Content.h"
#include "Article.h"

class Comment : public Content {
    std::string text;
    int userId;
public:
    Comment(std::string t, int uid) : text(std::move(t)), userId(uid) {}
    Comment(std::string t, int uid, int id) : text(std::move(t)), userId(id) {}

    void display() const override {
        std::ofstream file("comments.txt", std::ios::app); // Fájl megnyitása hozzáfűzési módban
        if (file.is_open()) {
            file << *this; // Kiírás fájlba az operátorral
            file.close();
        } else {
            std::cerr << "Nem sikerült megnyitni a fájlt. :(\n";
        }
    }

    std::string getType() const override { return "Komment"; }

    friend std::ostream& operator<<(std::ostream& os, const Comment& c) {
        os << "Komment (#" << c.userId << "): " << c.text << "\n";
        return os;
    }
};


    int getArticleId() const {return ArticleId; }

#endif //COMMENT_H
