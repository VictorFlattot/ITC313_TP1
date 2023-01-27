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
	/**
	 * @brief      Constructs a new instance.
	 */
	Library();

	/**
	 * @brief      Adds the specified b.
	 *
	 * @param      b     The book
	 */
	void add(Book& b);
	/**
	 * @brief      Adds the specified r.
	 *
	 * @param      r     The reader
	 */
	void add(Reader& r);
    /**
     * @brief      Adds the specified l.
     *
     * @param      l     The loan
     */
    void add(Loan& l);

    /**
     * @brief      Adds the specified books.
     *
     * @param[in]  books  The books
     */
    void add(const std::vector<Book>& books);
    /**
     * @brief      Adds the specified readers.
     *
     * @param[in]  readers  The readers
     */
    void add(const std::vector<Reader>& readers);
    /**
     * @brief      Adds the specified loans.
     *
     * @param[in]  loans  The loans
     */
    void add(const std::vector<Loan>& loans);

	/**
	 * @brief      Delete a book
	 *
	 * @param[in]  id    The identifier
	 */
	void delBook(int id);
    /**
     * @brief      Delete a reader
     *
     * @param[in]  id    The identifier
     */
    void delReader(int id);
	/**
	 * @brief      Delete a loan
	 *
	 * @param[in]  id    The identifier
	 */
	void delLoan(int id);

	/**
	 * @brief      Display all books in the terminal
	 *
	 * @param[in]  show  The show
	 *
	 * @return     a string that represent the books
	 */
	std::string displayBooks(bool show);
	/**
	 * @brief      Display all readers in the terminal
	 *
	 * @param[in]  show  The show
	 *
	 * @return     a string that represent the readers
	 */
	std::string displayReaders(bool show);
	/**
	 * @brief      Display all loans in the terminal
	 *
	 * @param[in]  show  The show
	 *
	 * @return     a string that represent the loans
	 */
	std::string displayLoans(bool show);

    /**
     * @brief      Determines whether the specified book b is in library.
     *
     * @param[in]  b     The book
     *
     * @return     True if the specified book b is in library, False otherwise.
     */
    bool isBookInLibrary(const Book& b);

	/**
	 * @brief      Loan a book
	 *
	 * @param      b         The book
	 * @param      r         The reader
	 * @param[in]  loanDate  The loan date
	 *
	 * @return     true if the return loan well, false otherwise
	 */
	bool loan(Book& b,Reader& r,const Date& loanDate = Date());
	/**
	 * @brief      Returns a book.
	 *
	 * @param      b     The book
	 * @param      r     The reader
	 *
	 * @return     true if the return went well, false otherwise

	 */
	bool returnBook(Book& b,Reader& r);

};

