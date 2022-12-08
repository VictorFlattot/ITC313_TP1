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
	Library() = default;

	void add(Book& b);
	void add(Reader& r);
    void add(Loan& l);

    void add(const std::vector<Book>& books);
    void add(const std::vector<Reader>& readers);
    void add(const std::vector<Loan>& loans);

	void delBook(int id);
    void delReader(int id);
	void delLoan(int id);

	std::string displayBooks(bool show);
	std::string displayReaders(bool show);
	std::string displayLoans(bool show);

    bool isBookInLibrary(const Book& b);

	bool loan(Book& b,Reader& r,const Date& loanDate = Date());
	bool returnBook(Book& b,Reader& r);

};

