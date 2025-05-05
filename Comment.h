#ifndef COMMENT_H
#define COMMENT_H

#include <string>
#include <iostream>
#include "Content.h"
#include "Article.h"

class Comment : public Content {
    std::string text;
    int userId;
    int ArticleId;
public:
    Comment(std::string t, int uid, int id);

    std::string getType() const override ;
    int getArticleId() const ;
    void display() const;

    friend std::ostream& operator<<(std::ostream& os, const Comment& c);
};

#endif // COMMENT_H
