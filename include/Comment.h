#ifndef COMMENT_H
#define COMMENT_H

#include <string>
#include <iostream>
#include "Content.h"
#include "Article.h"

using std::string, std::ostream, std::move;

class Comment : public Content {
    string text;       //maga a komment
    string username;   //felhasználónév
    string articleTitle;     //az újság Id-ja
public:
    Comment(string comment_, string username_, string articleTitle_);

    string getText () const { return text; }
    string getUsername () const { return username; }
    string getArticleTitle () const {return articleTitle; }
    string getType() const override { return "Komment"; }

    void setText (const string& text_) {text = text_;}
    void setUsername (const string& username_) {username = username_;}
    void setArticleTitle(const string& articleTitle_) { articleTitle = articleTitle_; }
    void display() const;
    friend ostream& operator<<(ostream& os, const Comment& comment_);
};

#endif // COMMENT_H
