#include "library.h"

#include <algorithm>
#include <iterator>

Library::Library() = default;


void Library::add(Book &b) { _books.push_back(b); }
void Library::add(Reader &r) { _readers.push_back(r); }
void Library::add(Loan &l) { _loans.push_back(l); }
void Library::add(const std::vector<Book> &books) { for (auto book: books) add(book); }
void Library::add(const std::vector<Reader> &readers) { for (auto reader: readers) add(reader); }

void Library::add(const std::vector<Loan> &loans) { for (auto loan: loans) add(loan); }
void Library::delBook(int id) {
    if (id < _books.size()) {
        _books.erase(_books.begin() + id);
    }
}
void Library::delReader(int id) {
    if (id < _readers.size()) {
        _readers.erase(_readers.begin() + id);
    }
}

void Library::delLoan(int id) {
    if (id < _loans.size()) {
        _loans.erase(_loans.begin() + id);
    }
}

std::string Library::displayBooks(bool show) {
    std::string ret;
    for (int i = 0; i < _books.size(); ++i) {
        ret += std::to_string(i) + " : \n" + to_string(_books.at(i)) + "\n";

    }
    if (show) std::cout << ret << std::endl;
    return ret;
}

std::string Library::displayReaders(bool show) {
    std::string ret;
    for (int i = 0; i < _readers.size(); ++i) {
        ret += std::to_string(i) + " : \n" + to_string(_readers.at(i)) + "\n";

    }
    if (show) std::cout << ret << std::endl;
    return ret;
}

std::string Library::displayLoans(bool show) {
    std::string ret;
    for (int i = 0; i < _loans.size(); ++i) {
        ret += std::to_string(i) + " : \n" + to_string(_loans.at(i)) + "\n";

    }
    if (show) std::cout << ret << std::endl;
    return ret;
}

bool Library::isBookInLibrary(const Book& b) {
    if (std::find(_books.begin(), _books.end(), b) != _books.end() )
        return true;
    return false;
}



bool Library::loan(Book &b, Reader &r, const Date &loanDate) {
    if (!isBookInLibrary(b)) return false;
    if (b.isBorrowed()) return false;
    b.setIsBorrowed(true);
    b.addLastBorrower(r.getSurname() + " " + r.getName());
    Loan l(b.getIsnb(), r.getId(), loanDate);
    add(l);
    return true;
}

bool Library::returnBook(Book &b, Reader &r) {
    if (!b.isBorrowed()) return false;
    if (b.getLastBorrower()  != r.getSurname() + " " + r.getName()) return false;
    b.setIsBorrowed(false);
    return true;
}





