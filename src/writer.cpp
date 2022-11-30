#include "writer.h"

#include <utility>

Writer::Writer(std::string name,std::string surname, Date birthdate,std::string id):
_id(std::move(id)), _name(std::move(name)), _surname(std::move(surname)), _birthdate(birthdate){};

std::string to_string(const Writer& w){

    if ((w.getBirthdate() == Date(1,1,0000)) && w.getName().empty() && w.getSurname().empty()) return "Inconnu";
    std::string result = w.getId();
    if (!w.getSurname().empty()) result += " - " + w.getSurname();
    if (!w.getName().empty()) result += + " " + w.getName();
    if (w.getBirthdate()!= Date(1,1,0000)) result += " - " + to_string(w.getBirthdate());
    return result;
}
