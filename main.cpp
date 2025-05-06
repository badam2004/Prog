#include <iostream>
#include "NewsPortal.h"

using namespace std;

int main() {
    NewsPortal portal;
    portal.readUsersFromFile("users.txt"); // fájlból olvassuk be a felhasználókat

    string username, password;
    cout << "Felhasználónév: ";
    cin >> username;
    cout << "Jelszó: ";
    cin >> password;

    if (!portal.authenticateUser(username, password)) {
        cerr << "Sikertelen bejelentkezés!" << endl;
        return 1;
    }

    cout << "Sikeres bejelentkezés! Üdv, " << username << "!" << endl;

    int choice;
    do {
        cout << "\n==== Menü ====\n";
        cout << "1. Cikkek listázása\n";
        cout << "2. Kommentek listázása egy cikkhez\n";
        cout << "3. Új cikk hozzáadása\n";
        cout << "4. Komment hozzáadása\n";
        cout << "0. Kilépés\n";
        cout << "Választás: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                portal.listArticles();
                break;
            }
            case 2: {
                string title;
                cout << "Cikk címe: ";
                getline(cin, title);
                portal.listCommentsForArticle(title);
                break;
            }
            case 3: {
                string title, content;
                if (User* user = portal.getUserByName(username); user && user->canPost()) {
                    cout << "Cikk címe: ";
                    getline(cin, title);
                    cout << "Tartalom: ";
                    getline(cin, content);
                    portal.addArticle(title, content, username);
                    cout << "Cikk sikeresen hozzáadva.\n";
                } else {
                    cout << "Nincs jogosultságod cikket írni.\n";
                }
                break;
            }
            case 4: {
                string article, comment;
                cout << "Melyik cikkhez (címmel): ";
                getline(cin, article);
                cout << "Komment szövege: ";
                getline(cin, comment);
                portal.addComment(comment, username, article);
                cout << "Komment hozzáadva.\n";
                break;
            }
            case 0: {
                cout << "Kilépés...\n";
                break;
            }
            default:
                cout << "Érvénytelen választás.\n";
        }
    } while (choice != 0);

    return 0;
}
