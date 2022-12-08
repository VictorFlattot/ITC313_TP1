#include "date.h"
#include "writer.h"
#include <utility>
#include <vector>
#include <string>
#include "language.h"
#include "genre.h"

#pragma once


class Book {
private:
    std::string _title;
    Writer _writer;
    Language _language;
    Genre _genre;
    Date _datePublished;
    std::string _isnb;
    std::vector<std::string> _lastsBorrowers;
    bool _isBorrowed;

public:
    explicit Book(std::string title = "Untitled", Writer writer = Writer(), Language language = Language::Unspecified,
                  Genre genre = Genre::Unspecified, Date datePublished = Date(01, 01, 0000),
                  std::string ISNB = "0000000000", std::vector<std::string> lastsBorrowers = {},
                  bool isBorrowed = false);

    void addLastBorrower(const std::string &borrower);

    std::string getTitle() const;

    const Writer &getWriter() const;
    Language getLanguage() const;
    Genre getGenre() const;
    const Date &getDatePublished() const;
    const std::string &getIsnb() const;
    const std::vector<std::string> &getLastsBorrowers() const;
    bool isBorrowed() const;
    void setTitle(const std::string &title);

    void setWriter(const Writer &writer);
    void setLanguage(Language language);
    void setGenre(Genre genre);
    void setDatePublished(const Date &datePublished);
    void setIsnb(const std::string &isnb);
    void setLastsBorrowers(const std::vector<std::string> &lastsBorrowers);
    void setIsBorrowed(bool isBorrowed);

    bool operator==(const Book &b) const;
    bool operator!=(const Book &rhs) const;

};

bool isBookValid(const std::string &title, Writer writer, Date published, const std::string &isnb);
bool isBookValid(Book book);

std::string displayVector(std::vector<std::string> const &strings);

std::string to_string(const Book &b);
std::ostream &operator<<(std::ostream &os, const Book &book);