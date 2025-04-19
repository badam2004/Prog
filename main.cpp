#include "Comment.h"
#include "NewsPortal.h"
#include "Article.h"
#include "User.h"
#include <iostream>

int main() {
    NewsPortal portal;

    // Tartalom hozzáadása (pointer nélkül)
    int articleId = portal.addArticle(
        "Nyakatekerés, azaz az AI nem gyerekjáték.",
        "A németországi von Haus bárót holtnak nyilvánították!",
        "Kvariczovszki László");

    portal.addComment("Nagyon hasznos cikk!", 123, articleId);

    // Felhasználók hozzáadása
    portal.addUser(User("Olvasó1", "reader"));
    portal.addUser(User("Szerző1", "author"));

    // Tartalom megjelenítése
    std::cout << "\nÖsszes tartalom:\n";
    portal.listArticles();

    std::cout << "\nKommentek a cikkhez:\n";
    portal.listCommentsForArticle(articleId);

    // Keresés
    std::cout << "\nKeresés szerző szerint:\n";
    auto results = portal.searchByAuthor("Kvariczovszki László");
    std::cout << "Találatok száma: " << results.size() << "\n";
    for (const auto *article: results) {
        article->display();
    }

    return 0;
}
