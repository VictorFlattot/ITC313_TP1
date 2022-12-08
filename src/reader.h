#include <string>
#include <vector>
#include <iostream>

#pragma once

class Reader {
private:
    std::string _name;
    std::string _surname;
    std::vector<std::string> _borrowedBooks;
    std::string _id;

public:
    explicit Reader(std::string name = "", std::string surname = "", std::vector<std::string> = {},
                    std::string id = std::to_string(rand()));

    //Getters
    const std::string &getName() const;
    const std::string &getSurname() const;
    const std::vector<std::string> &getBorrowedBooks() const;
    const std::string &getId() const;

    //Setters
    void setName(const std::string &name);
    void setSurname(const std::string &surname);
    void setBorrowedBooks(const std::vector<std::string> &borrowedBooks);
    void setId(const std::string &id);


};

//Helper functions
std::string to_string(Reader r);

//Operators
std::ostream &operator<<(std::ostream &os, const Reader &reader);
