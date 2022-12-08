#include "writer.h"

#include <utility>
#include <algorithm>
#include <iterator>

std::vector<std::string> existingId = {};

Writer::Writer(std::string name,std::string surname, Date birthdate,std::string id):
            _id(std::move(id)),
            _name(std::move(name)),
            _surname(std::move(surname)),
            _birthdate(birthdate){
    existingId.push_back(_id);
};

bool isIdValid(const std::string& id) {
    if ( std::find(existingId.begin(), existingId.end(), id) != existingId.end() )
        return true;
    return false;
}

bool isWriter(const std::string& name, const std::string& surname, Date birthdate, const std::string& id) {
    if (name.empty() && surname.empty()) return false;
    if (!isDate(birthdate)) return false;
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