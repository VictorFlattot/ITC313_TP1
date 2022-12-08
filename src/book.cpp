#include "book.h"
#include <iostream>
#include <utility>


Book::Book(std::string title, Writer writer, Language language, Genre genre, Date datePublished,
           std::string ISNB, std::vector<std::string> lastsBorrowers, bool isBorrowed) :
        _title(std::move(title)), _writer(std::move(writer)),
        _language(language),
        _genre(genre),
        _datePublished(datePublished),
        _isnb(std::move(ISNB)),
        _lastsBorrowers(std::move(lastsBorrowers)),
        _isBorrowed(isBorrowed) {}

bool isBook(const std::string &title, Writer writer, Date published, const std::string &isnb) {
    if (title.empty()) return false;
    if (!isWriter(std::move(writer))) return false;
    if (!isDate(published)) return false;
    if (isnb.size() != 10) return false;
    return true;
}

bool isBook(const Book &book) {
    return isBook(book.getTitle(), book.getWriter(), book.getDatePublished(), book.getISNB());
}


std::string displayVector(std::vector<std::string> const &strings) {
    std::string result = "  \n";
    for (std::size_t i = 0; i < strings.size();)
        result += "  " + strings[i++] + "\n";
    return result;
}

std::string to_string(const Book &b) {
    return "Title: " + b.getTitle() + "\n" +
           "Writer : " + to_string(b.getWriter()) + "\n" +
           "Language : " + language_str.at(static_cast<char>(b.getLanguage())) + "\n" +
           "Genre : " + genre_str.at(static_cast<char>(b.getGenre())) + "\n" +
           "Publication date : " + to_string(b.getDatePublished()) + "\n" +
           "ISBN : " + b.getISNB() + "\n" +
           "Last borrowers : " + displayVector(b.getLastsBorrowers());
}

std::ostream &operator<<(std::ostream &os, const Book &book) {
    os << to_string(book) << std::endl;
    return os;
}