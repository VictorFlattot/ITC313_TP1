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
	/**
     * @brief      Constructs a new instance.
     *
     * @param[in]  name       The name
     * @param[in]  surname    The surname
     * @param[in]  birthdate  The birthdate
     * @param[in]  id         The identifier
     */
    explicit Writer(std::string name = "", std::string surname = "", Date birthdate = Date(1, 1, 0000),std::string id = std::to_string(rand()));

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
     * @brief      Gets the birthdate.
     *
     * @return     The birthdate.
     */
    const Date &getBirthdate() const;
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
     * @brief      Sets the birthdate.
     *
     * @param[in]  birthdate  The birthdate
     */
    void setBirthdate(const Date &birthdate);
    /**
     * @brief      Sets the identifier.
     *
     * @param[in]  id    The new value
     */
    void setId(const std::string &id);

    /**
     * @brief      Equality operator.
     *
     * @param[in]  w     the writer
     *
     * @return     The result of the equality
     */
    bool operator == (const Writer& w) const; // d1 == d2
    //
    // @param[in]  w     the writer
    //
    // @return     The result of the inequality
    //
    bool operator != (const Writer& w) const; // d1 != d2

};

/**
 * @brief      Determines whether the specified identifier is valid.
 *
 * @param[in]  id    The identifier
 *
 * @return     True if the specified identifier is valid, False otherwise.
 */
bool isIdValid(const std::string& id);

/**
 * @brief      Determines if writer is valid.
 *
 * @param[in]  name       The name
 * @param[in]  surname    The surname
 * @param[in]  birthdate  The birthdate
 * @param[in]  id         The identifier
 *
 * @return     True if writer is valid, False otherwise.
 */
bool isWriter(const std::string& name , const std::string& surname,Date birthdate, const std::string& id);
/**
 * @brief      Determines whether the specified wrtier w is valid.
 *
 * @param[in]  w     the writer
 *
 * @return     True if the specified writer w is valid, False otherwise.
 */
bool isWriter(Writer w) ;

/**
 * @brief      Get a string description of the writer w
 *
 * @param[in]  w     the writer
 *
 * @return     a string description of the reader r
 */
std::string to_string(const Writer& w);
/**
 * @brief      Bitwise left shift operator.
 *
 * @param      os      The operating system
 * @param[in]  writer  The writer
 *
 * @return     The result of the bitwise left shift
 */
std::ostream& operator<<(std::ostream& os, const Writer& writer);