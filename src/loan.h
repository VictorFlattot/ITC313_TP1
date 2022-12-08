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
    explicit Loan (std::string isnb = "", std::string id = "", const Date &loanDate = Date());

    const std::string &getIsnb() const;
    const std::string &getId() const;
    const Date &getLoanDate() const;

    void setIsnb(const std::string &isnb);
    void setId(const std::string &id);
    void setLoanDate(const Date &loanDate);

};

bool isLoanValid(const std::string& isbn, const std::string& id, const Date& loanDate);

std::string to_string(const Loan& l);
std::ostream& operator<<(std::ostream& os, const Loan& loan);
