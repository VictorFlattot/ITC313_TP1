#include "writer.h"

#include <utility>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <iostream>

std::vector<std::string> existingId = {};

Writer::Writer(std::string name,std::string surname, Date birthdate,std::string id):
            _id(std::move(id)),
            _name(std::move(name)),
            _surname(std::move(surname)),
            _birthdate(birthdate){
    bool status = isWriter(_name,_surname,_birthdate, _id);
    assert(status && "Writer is not valid");
    existingId.push_back(_id);
};

const std::string &Writer::getName() const { return _name; }
const std::string &Writer::getSurname() const { return _surname; }
const Date &Writer::getBirthdate() const { return _birthdate; }
const std::string &Writer::getId() const { return _id; }

void Writer::setName(const std::string &name) { _name = name; }
void Writer::setSurname(const std::string &surname) { _surname = surname; }
void Writer::setBirthdate(const Date &birthdate) { _birthdate = birthdate; }
void Writer::setId(const std::string &id) { _id = id; }

bool Writer::operator==(const Writer &w) const {
    if (_name == w.getName() && _surname == w.getSurname() && _birthdate == w.getBirthdate() && _id == w.getId()){
        return true;
    }
    return false;
}

bool Writer::operator!=(const Writer &w) const { return false; }

bool isIdValid(const std::string& id) {
    // display existingId
    for (auto it : existingId) {
        std::cout << it << std::endl;
    }
    std::cout << "ok" << std::endl;
    if ((std::find(existingId.begin(), existingId.end(), id) != existingId.end()))
        return false;
    return true;
}

bool isWriter(const std::string& name, const std::string& surname, Date birthdate, const std::string& id) {

    if (!isDate(birthdate)) return false;
    if (name.empty() && surname.empty()) return false;
    if (!isIdValid(id)) return false;
    return true;

}

bool isWriter(Writer w) {
    return isWriter(w.getName(), w.getSurname(), w.getBirthdate(), w.getId());
}

std::string to_string(const Writer& w){

    if ((w.getBirthdate() == Date(1,1,0000)) && w.getName().empty() && w.getSurname().empty()) return "Unknown";
    std::string result = w.getId();
    if (!w.getSurname().empty()) result += " - " + w.getSurname();
    if (!w.getName().empty()) result += + " " + w.getName();
    if (w.getBirthdate()!= Date(1,1,0000)) result += " - " + to_string(w.getBirthdate());
    return result;
}

std::ostream& operator<<(std::ostream& os, const Writer& writer) {
    os << to_string(writer) << std::endl;
    return os;
}