//
// Created by Shadow on 30/11/2022.
//
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
    explicit Reader(std::string name = "", std::string surname = "", std::vector<std::string> = {},std::string id = std::to_string(rand()));

    void setName(std::string& name) { _name = name;}
    void setSurname(std::string& surname) { _surname = surname;}
    void setBorrowedBooks(std::vector<std::string>& borrowedBooks) { _borrowedBooks = borrowedBooks;}
    void setId(std::string& id) { _id = id;}

    std::string getName() const { return _name; }
    std::string getSurname() const { return _surname; }
    std::vector<std::string> getBorrowedBooks() const { return _borrowedBooks;}
    std::string getId() const { return _id; }
};

std::string to_string(const Reader& r);
std::ostream& operator<<(std::ostream& os, const Reader& reader);
