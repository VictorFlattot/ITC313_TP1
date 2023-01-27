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
    /**
     * @brief      Constructs a new instance.
     *
     * @param[in]  name       The name
     * @param[in]  surname    The surname
     * @param[in]  <unnamed>  { parameter_description }
     * @param[in]  id         The identifier
     */
    explicit Reader(std::string name = "", std::string surname = "", std::vector<std::string> borrowedBooks = {},
                    std::string id = std::to_string(rand()));

    
    /**
     * @brief      Gets the name.
     *
     * @return     The name.
     */
    const std::string &getName() const;
    /**
     * @brief      Gets the surname.
     *
     * @return     The surname.
     */
    const std::string &getSurname() const;
    /**
     * @brief      Gets the borrowed books.
     *
     * @return     The borrowed books.
     */
    const std::vector<std::string> &getBorrowedBooks() const;
    /**
     * @brief      Gets the identifier.
     *
     * @return     The identifier.
     */
    const std::string &getId() const;

    
    /**
     * @brief      Sets the name.
     *
     * @param[in]  name  The name
     */
    void setName(const std::string &name);
    /**
     * @brief      Sets the surname.
     *
     * @param[in]  surname  The surname
     */
    void setSurname(const std::string &surname);
    /**
     * @brief      Sets the borrowed books.
     *
     * @param[in]  borrowedBooks  The borrowed books
     */
    void setBorrowedBooks(const std::vector<std::string> &borrowedBooks);
    /**
     * @brief      Sets the identifier.
     *
     * @param[in]  id    The new value
     */
    void setId(const std::string &id);


};

/**
 * @brief      Get a string description of the reader r
 *
 * @param[in]  r The reader
 *
 * @return     a string description of the reader r
 */
std::string to_string(Reader r);

/**
 * @brief      Bitwise left shift operator.
 *
 * @param      os      The operating system
 * @param[in]  reader  The reader
 *
 * @return     The result of the bitwise left shift
 */
std::ostream &operator<<(std::ostream &os, const Reader &reader);
