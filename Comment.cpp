#include "Comment.h"

// Konstruktor
Comment::Comment(std::string t, int uid, int id) : text(std::move(t)), userId(uid), ArticleId(id) {}

std::string Comment::getType() const {
    return "Komment";
}

int Comment::getArticleId() const {
    return (this->ArticleId);
}

void Comment::display() const {
    std::cout << *this;
}

// << operátor túlterhelése
std::ostream& operator<<(std::ostream& os, const Comment& c) {
    os << "Komment (#" << c.userId << "): " << c.text << "\n";
    return os;
}
