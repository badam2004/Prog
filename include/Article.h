#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>
#include <iostream>
#include "Content.h"

using std::string, std::cout;

class Article : public Content {
private:
    string title;
    string content;
    string author;
public:
    // Konstruktor
    Article(string title_, string content_, string author_): title(title_), content(content_), author(author_) {}
    // Getterek
    string getTitle() const { return title; }
    string getContent() const {return content; }
    string getAuthor() const { return author; }
    string getType() const { return "Cikk"; }
    // Setterek
    void setTitle(const string& title_) { title = title_; }
    void setContent(const string& content_) { content = content_; }
    void setAuthor(const string& author_) { author = author_; }

    // Kiiratás
    void display() const override{
    cout << "Cikk: " << title << "\nSzerzõ: " << author << "\n" << content << "\n";
    }

};

#endif // ARTICLE_H
