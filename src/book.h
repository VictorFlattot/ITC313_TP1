#include "date.h"
#include "writer.h"
#include <vector>
#include <string>
#include "language.h"
#include "genre.h"

#pragma once



class Book
{
private:
	std::string _title;
	Writer _writer;
	Language _language;
	Genre _genre;
	Date _datePublished;
	std::string _ISNB;
	std::vector<std::string> _lastsBorrowers;

public:
    Book(std::string title = "Untitled", Writer  writer = Writer(), Language language = Language::Unspecified,
         Genre genre = Genre::Unspecified, Date datePublished = Date(01,01,0000),
         std::string ISNB = "0000000000", std::vector<std::string> lastsBorrowers = {});

    std::string getTitle() const { return _title;}
	Writer getWriter() const { return _writer;}
	Language getLanguage() const { return _language;}
	Genre getGenre() const { return _genre;}
	Date getDatePublished() const { return _datePublished;}
	std::string getISNB() const { return _ISNB;}
	std::vector<std::string> getLastsBorrowers() const { return _lastsBorrowers;};

	void setTitle(std::string title) { _title = title;}
	void setWriter(Writer writer) { _writer = writer;}
	void setLanguage(Language language) { _language = language;}
	void setGenre(Genre genre) { _genre = genre;}
	void setDatePublished(Date datePublished) { _datePublished = datePublished;}
	void setISNB(std::string ISNB) { _ISNB = ISNB;}
	void setLastsBorrowers(std::vector<std::string> lastBorrowers) { _lastsBorrowers = lastBorrowers;}

};

std::string displayVector(std::vector<std::string> const& strings);
std::string to_string(const Book& b);
std::ostream& operator<<(std::ostream& os, const Book& book);