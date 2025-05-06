#include "NewsPortal.h"
#include <iostream>
#include <fstream>
#include <sstream>

void NewsPortal::addArticle(const string& title_, const string& content_, const string& author_) {
    Article temp(title_, content_, author_);
    articles.push_back(temp);
}

void NewsPortal::addComment(const string& comment_, const string& username_, const string& articleTitle_) {
    bool found = false;

    for (const auto& article : articles)
        if (article.getTitle() == articleTitle_) {
            found = true;
            break;
        }

    if (!found) {
        cerr << "Hiba: Nem található olyan cikk, amelynek címe: \"" << articleTitle_;
        return;
    }

    Comment temp(comment_, username_, articleTitle_);
    comments.push_back(temp);
}

void NewsPortal::listArticles() const {
    for (const auto& article : articles) {
        article.display();
    }
}

void NewsPortal::listCommentsForArticle(const string& articleTitle_) const {
    for (const auto& temp : comments){
        if (temp.getArticleTitle() == articleTitle_){
            cout << temp.getText() << endl;
        }
    }
    cout << "Nem találtam Kommentet az újsághoz!" << endl;

}

vector<Article> NewsPortal::searchByAuthor(const string& author_) {
    vector<Article> temp;
    for (const auto& i : articles)
        if (i.getAuthor() == author_)
            temp.push_back(i);
    return temp;
}

vector<Article> NewsPortal::searchByTitle(const string& title_) {
    vector<Article> temp;
    for (const auto& i : articles)
        if (i.getTitle() == title_)
            temp.push_back(i);
    return temp;
}

void NewsPortal::readUsersFromFile(const string& filename) {
    std::ifstream file(filename);
    string line;

    if (!file) {
        std::cerr << "Nem lehet a fájlt megnyitni!" << std::endl;
        exit(-1);
    }

    while (std::getline(file, line)) {
        string username, password;
        int role;
        std::istringstream iss(line);
        if (iss >> username >> password >> role) {
            User temp(username, password, role);
            users.push_back(temp);
        }
    }
}


User* NewsPortal::getUserByName(const string& username) {
    for (auto& user : users) {
        if (user.getUsername() == username)
            return &user;
    }
    return nullptr;
}


/*
bool NewsPortal::authenticateUser(const string& username, const string& password)
{
    int userIndex = -1;
        for (unsigned i = 0; i < users.size(); i++)
            if (users[i].getUsername() == username)
                userIndex = i;

        if (userIndex == -1) {
            std::cerr << "Nincs ilyen nevu user (NP): " << username;
            exit(-1);
        }
    return users[userIndex].getPassword() == password;
}
*/

bool NewsPortal::authenticateUser(const string& username, const string& password) {
    for (const auto& user : users) {
        if (user.getUsername() == username && user.getPassword() == password) {
            return true;
        }
    }
    return false;
}


