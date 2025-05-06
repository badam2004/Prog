#ifndef TMP_H
#define TMP_H


#include <string>

class TMP {
    std::string text;
    int userId;
    int articleId;
public:
    TMP(const std::string& t, int uid, int aid) : text(t), userId(uid), articleId(aid) {};
    std::string getText() const;
    int getUserId() const;
    int getArticleId() const;
};

#endif // TMP_H
