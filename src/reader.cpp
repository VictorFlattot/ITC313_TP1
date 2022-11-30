//
// Created by Shadow on 30/11/2022.
//

#include "reader.h"


Reader::Reader(std::string name, std::string surname, std::vector<std::string> borrowedBooks, std::string id):
    _name(std::move(name)),
    _surname(std::move(surname)),
    _borrowedBooks(std::move(borrowedBooks)),
    _id(std::move(id)){}

std::string to_string(const Reader& r){
    std::string result = r.getId();
    if (!r.getSurname().empty()) result += " - " + r.getSurname();
    if (!r.getName().empty()) result += + " " + r.getName();
    return result;
}

std::ostream& operator<<(std::ostream& os, const Reader& reader) {
    os << to_string(reader) << std::endl;
    return os;
}