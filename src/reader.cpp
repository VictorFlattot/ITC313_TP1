//
// Created by Shadow on 30/11/2022.
//

#include "reader.h"


Reader::Reader(std::string name, std::string surname, std::vector<std::string> borrowedBooks, std::string id):
    _name(std::move(name)),
    _surname(std::move(surname)),
    _borrowedBooks(std::move(borrowedBooks)),
    _id(std::move(id)){}

//Getters
const std::string &Reader::getName() const { return _name; }
const std::string &Reader::getSurname() const { return _surname; }
const std::vector<std::string> &Reader::getBorrowedBooks() const { return _borrowedBooks; }
const std::string &Reader::getId() const { return _id; }

//Setters
void Reader::setName(const std::string &name) { _name = name; }
void Reader::setSurname(const std::string &surname) { _surname = surname; }
void Reader::setBorrowedBooks(const std::vector<std::string> &borrowedBooks) { _borrowedBooks = borrowedBooks; }
void Reader::setId(const std::string &id) { _id = id; }

//Helper functions
std::string to_string(Reader r){
    std::string result = r.getId();
    if (!r.getSurname().empty()) result += " - " + r.getSurname();
    if (!r.getName().empty()) result += + " " + r.getName();
    return result;
}

//Operators
std::ostream& operator<<(std::ostream& os, const Reader& reader) {
    os << to_string(reader) << std::endl;
    return os;
}