//
// Created by Shadow on 30/11/2022.
//

#include <cassert>
#include "loan.h"

Loan::Loan(std::string isnb, std::string id,const Date& loanDate) :
        _isnb(isnb),
        _id(id),
        _loanDate(loanDate){
    bool status = isLoanValid(isnb, id, loanDate);
    assert(status && "Date is not valid");
}

std::string to_string(const Loan& l){
    return "ISNB : " + l.getIsnb() + "\n" +
    "Reader ID : " + l.getId() + "\n" +
    "Loan Date : " + to_string(l.getLoanDate());
}

std::ostream& operator<<(std::ostream& os, const Loan& loan) {
    os << to_string(loan) << std::endl;
    return os;
}

bool isLoanValid(const std::string& isbn, const std::string& id, const Date& loanDate){
    if (isbn.empty()) return false;
    if (isbn.size()!= 10) return false;
    if (id.empty()) return false;
    return true;

}
