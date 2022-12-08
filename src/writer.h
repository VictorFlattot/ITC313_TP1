#include <string>
#include <vector>
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

    const std::string &getName() const;
    const std::string &getSurname() const;
    const Date &getBirthdate() const;
    const std::string &getId() const;

    void setName(const std::string &name);
    void setSurname(const std::string &surname);
    void setBirthdate(const Date &birthdate);
    void setId(const std::string &id);

    bool operator == (const Writer& w) const; // d1 == d2
    bool operator != (const Writer& w) const; // d1 != d2

};

bool isIdValid(const std::string& id);

bool isWriter(const std::string& name , const std::string& surname,Date birthdate, const std::string& id);
bool isWriter(Writer w) ;

std::string to_string(const Writer& w);
std::ostream& operator<<(std::ostream& os, const Writer& writer);