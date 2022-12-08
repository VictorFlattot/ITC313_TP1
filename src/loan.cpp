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
    assert(status && "Loan is not valid");
    
}

const std::string &Loan::getIsnb() const { return _isnb; }
const std::string &Loan::getId() const { return _id; }
const Date &Loan::getLoanDate() const { return _loanDate; }

void Loan::setIsnb(const std::string &isnb) { _isnb = isnb; }
void Loan::setId(const std::string &id) { _id = id; }
void Loan::setLoanDate(const Date &loanDate) { _loanDate = loanDate; }

bool isLoanValid(const std::string& isbn, const std::string& id, const Date& loanDate){
    if (isbn.empty()) return false;
    if (isbn.size()!= 10) return false;
    if (id.empty()) return false;
    return true;
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
