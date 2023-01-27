//
// Created by Shadow on 30/11/2022.
//

#pragma once

#include "date.h"
#include <string>

class Loan {
    private:
    std::string _isnb;
    std::string _id;
    Date _loanDate;

    public:
    /**
     * @brief      Constructs a new instance.
     *
     * @param[in]  isnb      The isnb
     * @param[in]  id        The identifier
     * @param[in]  loanDate  The loan date
     */
    explicit Loan (const std::string& isnb = "", const std::string& id = "", const Date &loanDate = Date());

    /**
     * @brief      Gets the isnb.
     *
     * @return     The isnb.
     */
    std::string getIsnb() const;
    /**
     * @brief      Gets the identifier.
     *
     * @return     The identifier.
     */
    std::string getId() const;
    /**
     * @brief      Gets the loan date.
     *
     * @return     The loan date.
     */
    const Date &getLoanDate() const;

    /**
     * @brief      Sets the isnb.
     *
     * @param[in]  isnb  The isnb
     */
    void setIsnb(std::string isnb);
    /**
     * @brief      Sets the identifier.
     *
     * @param[in]  id    The new value
     */
    void setId(std::string id);
    /**
     * @brief      Sets the loan date.
     *
     * @param[in]  loanDate  The loan date
     */
    void setLoanDate(const Date &loanDate);

};

/**
 * @brief      Determines if loan is valid.
 *
 * @param[in]  isbn      The isbn
 * @param[in]  id        The identifier
 * @param[in]  loanDate  The loan date
 *
 * @return     True if loan is valid, False otherwise.
 */
bool isLoanValid(const std::string& isbn, const std::string& id, const Date& loanDate);

/**
 * @brief      Get a string description of the loan l
 *
 * @param[in]  l The loan
 *
 * @return     a string description of the loan l
 */
std::string to_string(const Loan& l);
/**
 * @brief      Bitwise left shift operator.
 *
 * @param      os    The operating system
 * @param[in]  loan  The loan
 *
 * @return     The result of the bitwise left shift
 */
std::ostream& operator<<(std::ostream& os, const Loan& loan);
