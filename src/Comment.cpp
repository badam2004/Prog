#include "Comment.h"

// Konstruktor
Comment::Comment(string comment_, string username_, string articleTitle_)
    : text(move(comment_)), username(move(username_)), articleTitle(move(articleTitle_)) {}

void Comment::display() const {
    cout << *this;
};

// << oper�tor t�lterhel�se
ostream& operator<<(ostream& os, const Comment& comment_) {
    os << "Komment (#" << comment_.username << "): " << comment_.text << "\n";
    return os;
};
