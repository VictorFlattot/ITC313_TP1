#include <string>
#include "date.h"

#pragma once

class Writer
{
private:
    std::string _name;
    std::string _surname;
    Date _birthdate;
    std::string _id;

public:
	explicit Writer(std::string name = "", std::string surname = "", Date birthdate = Date(1, 1, 0000),std::string id = std::to_string(rand()));

    void setId(std::string& id) { _id = id; };
    void setName(std::string& name) { _name = name; };
    void setSurname(std::string& surname) { _surname = surname;}
    void setBirthdate(Date& birthdate) { _birthdate = birthdate; };

    std::string getId() const { return _id; };
    std::string getName() const { return _name; };
    std::string getSurname() const { return _surname; };
    Date getBirthdate() const { return _birthdate; };

};
std::string to_string(const Writer& w);
std::ostream& operator<<(std::ostream& os, const Writer& writer);