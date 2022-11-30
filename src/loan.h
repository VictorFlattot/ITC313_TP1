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
    Loan (std::string isnb = "", std::string id = "", const Date &loanDate = Date());

    void setIsnb(std::string& isnb) { _isnb = isnb; }
    void setId(std::string& id) { _id = id; }
    void setLoanDate(const Date &loanDate) { _loanDate = loanDate;}

    const std::string &getIsnb() const { return _isnb; }
    const std::string &getId() const { return _id; }
    const Date &getLoanDate() const { return _loanDate; }

};

bool isLoanValid(const std::string& isbn, const std::string& id, const Date& loanDate);
std::string to_string(const Loan& l);
std::ostream& operator<<(std::ostream& os, const Loan& loan);
