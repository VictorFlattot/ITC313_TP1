#include "book.h"
#include "reader.h"
#include "loan.h"

#pragma once

class Library
{
private:
	std::vector<Book> _books;
	std::vector<Reader> _readers;
	std::vector<Loan> _loans;

public:
	Library();

	void add(Book& b);
	void add(Reader& r);
	void add(Loan& l);

	void delBook(int id);
	void delReader(int id);
	void delLoan(int id);

	std::string displayBooks(bool show);
	std::string displayReaders(bool show);
	std::string displayLoans(bool show);

	bool loan(Book& b,Reader& r,const Date& loanDate = Date());
	bool returnBook(Book& b,Reader& r);

};

