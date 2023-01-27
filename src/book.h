#include "date.h"
#include "writer.h"
#include <utility>
#include <vector>
#include <string>
#include "language.h"
#include "genre.h"

#pragma once


class Book {
private:
    std::string _title;
    Writer _writer;
    Language _language;
    Genre _genre;
    Date _datePublished;
    std::string _isnb;
    std::vector<std::string> _lastsBorrowers;
    bool _isBorrowed;

public:
    /**
     * @brief      Constructs a new instance.
     *
     * @param[in]  title           The title
     * @param[in]  writer          The writer
     * @param[in]  language        The language
     * @param[in]  genre           The genre
     * @param[in]  datePublished   The date published
     * @param[in]  ISNB            The isnb
     * @param[in]  lastsBorrowers  The lasts borrowers
     * @param[in]  isBorrowed      Indicates if borrowed
     */
    explicit Book(std::string title = "Untitled", Writer writer = Writer(), Language language = Language::Unspecified,
                  Genre genre = Genre::Unspecified, Date datePublished = Date(01, 01, 0000),
                  std::string ISNB = "0000000000", std::vector<std::string> lastsBorrowers = {},
                  bool isBorrowed = false);

    /**
     * @brief      Adds a last borrower.
     *
     * @param[in]  borrower  The borrower
     */
    void addLastBorrower(const std::string &borrower);
    /**
     * @brief      Gets the last borrower.
     *
     * @return     The last borrower.
     */
    std::string getLastBorrower();

    /**
     * @brief      Gets the title.
     *
     * @return     The title.
     */
    std::string getTitle() const;

    /**
     * @brief      Gets the writer.
     *
     * @return     The writer.
     */
    const Writer &getWriter() const ;
    /**
     * @brief      Gets the language.
     *
     * @return     The language.
     */
    Language getLanguage() const;
    /**
     * @brief      Gets the genre.
     *
     * @return     The genre.
     */
    Genre getGenre() const;
    /**
     * @brief      Gets the date published.
     *
     * @return     The date published.
     */
    const Date &getDatePublished() const;
    /**
     * @brief      Gets the isnb.
     *
     * @return     The isnb.
     */
    const std::string &getIsnb() const;
    /**
     * @brief      Gets the lasts borrowers.
     *
     * @return     The lasts borrowers.
     */
    const std::vector<std::string> &getLastsBorrowers() const;
    /**
     * @brief      Determines if borrowed.
     *
     * @return     True if borrowed, False otherwise.
     */
    bool isBorrowed() const;

    /**
     * @brief      Sets the title.
     *
     * @param[in]  title  The title
     */
    void setTitle(const std::string &title);
    /**
     * @brief      Sets the writer.
     *
     * @param[in]  writer  The writer
     */
    void setWriter(const Writer &writer);
    /**
     * @brief      Sets the language.
     *
     * @param[in]  language  The language
     */
    void setLanguage(Language language);
    /**
     * @brief      Sets the genre.
     *
     * @param[in]  genre  The genre
     */
    void setGenre(Genre genre);
    /**
     * @brief      Sets the date published.
     *
     * @param[in]  datePublished  The date published
     */
    void setDatePublished(const Date &datePublished);
    /**
     * @brief      Sets the isnb.
     *
     * @param[in]  isnb  The isnb
     */
    void setIsnb(const std::string &isnb);
    /**
     * @brief      Sets the lasts borrowers.
     *
     * @param[in]  lastsBorrowers  The lasts borrowers
     */
    void setLastsBorrowers(const std::vector<std::string> &lastsBorrowers);
    /**
     * @brief      Sets the is borrowed.
     *
     * @param[in]  isBorrowed  Indicates if borrowed
     */
    void setIsBorrowed(bool isBorrowed);

    /**
     * @brief      Equality operator.
     *
     * @param[in]  b     The book
     *
     * @return     The result of the equality
     */
    bool operator==(const Book &b) const;
    /**
     * @brief      Inequality operator.
     *
     * @param[in]  rhs   The right hand side
     *
     * @return     The result of the inequality
     */
    bool operator!=(const Book &rhs) const;

};

/**
 * @brief      Determines if book is valid.
 *
 * @param[in]  title      The title
 * @param[in]  writer     The writer
 * @param[in]  published  The published
 * @param[in]  isnb       The isnb
 *
 * @return     True if book is valid, False otherwise.
 */
bool isBookValid(const std::string &title, Writer writer, Date published, const std::string &isnb);
/**
 * @brief      Determines whether the specified book is valid.
 *
 * @param[in]  book  The book
 *
 * @return     True if the specified book is valid, False otherwise.
 */
bool isBookValid(Book book);

/**
 * @brief      Display any std::vector<std::string> in the terminal
 *
 * @param      strings  The strings
 *
 * @return     a string represent the vector of strings 
 */
std::string displayVector(std::vector<std::string> const &strings);

std::string to_string(const Book &b);
std::ostream &operator<<(std::ostream &os, const Book &book);