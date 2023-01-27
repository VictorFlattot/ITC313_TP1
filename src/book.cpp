#include "book.h"
#include <iostream>
#include <utility>
#include <algorithm>
#include <iterator>

Book::Book(std::string title, Writer writer, Language language, Genre genre, Date datePublished,
           std::string ISNB, std::vector<std::string> lastsBorrowers, bool isBorrowed) :
        _title(std::move(title)), _writer(std::move(writer)),
        _language(language),
        _genre(genre),
        _datePublished(datePublished),
        _isnb(std::move(ISNB)),
        _lastsBorrowers(std::move(lastsBorrowers)),
        _isBorrowed(isBorrowed) {}


bool isBookValid(const std::string &title, Writer writer, Date published, const std::string &isnb) {
    if (title.empty()) return false;
    if (!isWriter(std::move(writer))) return false;
    if (!isDate(published)) return false;
    if (isnb.size() != 10 || isnb.size() != 13) return false;
    return true;
}

bool isBookValid(Book &book) {
    return isBookValid(book.getTitle(), book.getWriter(), book.getDatePublished(), book.getIsnb());
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
           "ISBN : " + b.getIsnb() + "\n" +
           "Last borrowers : " + displayVector(b.getLastsBorrowers());
}

std::string Book::getTitle() const {
    if (_title.empty()) return "Untitled";
    return _title;
}

const Writer &Book::getWriter() const { return _writer; }

Language Book::getLanguage() const { return _language; }

Genre Book::getGenre() const { return _genre; }

const Date &Book::getDatePublished() const { return _datePublished; }

const std::string &Book::getIsnb() const { return _isnb; }

const std::vector<std::string> &Book::getLastsBorrowers() const { return _lastsBorrowers; }

bool Book::isBorrowed() const { return _isBorrowed; }

void Book::setTitle(const std::string &title) { _title = title; }

void Book::setWriter(const Writer &writer) { _writer = writer; }

void Book::setLanguage(Language language) { _language = language; }

void Book::setGenre(Genre genre) { _genre = genre; }

void Book::setDatePublished(const Date &datePublished) { _datePublished = datePublished; }

void Book::setIsnb(const std::string &isnb) { _isnb = isnb; }

void Book::setLastsBorrowers(const std::vector<std::string> &lastsBorrowers) { _lastsBorrowers = lastsBorrowers; }

void Book::setIsBorrowed(bool isBorrowed) { _isBorrowed = isBorrowed; }

void Book::addLastBorrower(const std::string &borrower) { _lastsBorrowers.push_back(borrower); }

std::string Book::getLastBorrower() { return _lastsBorrowers.at(_lastsBorrowers.size() - 1); }

bool Book::operator==(const Book &b) const {
    return _title == b._title &&
           _writer == b._writer &&
           _language == b._language &&
           _genre == b._genre &&
           _datePublished == b._datePublished &&
           _isnb == b._isnb;
}

bool Book::operator!=(const Book &b) const { return !(b == *this); }

std::ostream &operator<<(std::ostream &os, const Book &book) {
    os << to_string(book) << std::endl;
    return os;
}
