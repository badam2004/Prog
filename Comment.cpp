#include "Comment.h"
#include <fstream>

// Konstruktorok
Comment::Comment(std::string t, int uid) : text(std::move(t)), userId(uid) {}

Comment::Comment(std::string t, int uid, int id) : text(std::move(t)), userId(uid) {
    this->id = id; // Feltételezve, hogy az id az ősosztályban van
}

// Display fájlba írással
std::ostream& Comment::display() const {
    os << "Komment (#" << c.userId << "): " << c.text << "\n";
    return os;
}

std::string Comment::getType() const {
    return "Komment";
}

// Feltételezve, hogy ArticleId elérhető (pl. öröklés vagy saját változó)
int Comment::getArticleId() const {
    return ArticleId;
}

// << operátor túlterhelése
std::ostream& operator<<(std::ostream& os, const Comment& c) {
    os << "Komment (#" << c.userId << "): " << c.text << "\n";
    return os;
}
