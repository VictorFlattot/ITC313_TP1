#include "library.h"
#include <iostream>

#include <random>
#include <algorithm>

void testDate() {
    Date end_of_world(12, 12 , 2012);
    Date end_of_world2(12, 12 , 2012);
    Date other_date(25, 12 , 2022);

    //Equality
    bool test = other_date == end_of_world;
    std::cout << "25/12/2022 == End of World ? " << std::to_string(test) << std::endl;
    test = other_date !=  end_of_world;
    std::cout << "25/12/2022 != End of World ? " << std::to_string(test) << std::endl;
    test = end_of_world == end_of_world2;
    std::cout << "25/12/2012 == End of World ? " << std::to_string(test) << std::endl;

    // Comparison
    test = other_date > end_of_world;
    std::cout << "25/12/2022 > End of World : " << std::to_string(test) << std::endl;
    test = Date(1, 1, 2010) > Date(1, 1, 2010);
    std::cout << "01/01/2010 > 01/01/2010 : " << std::to_string(test) << std::endl;
    test = Date(1, 1, 2010) > Date(2, 1, 2010);
    std::cout << "01/01/2010 > 01/01/2010 : " << std::to_string(test) << std::endl;

    test = other_date < end_of_world;
    std::cout << "25/12/2022 < End of World : " << std::to_string(test) << std::endl;
    test = Date(1, 1, 2010) < Date(1, 1, 2015) ;
    std::cout << "01/01/2010 < 01/01/2015: " << std::to_string(test) << std::endl;
    test = Date(1, 1, 2010) < Date(1, 2, 2010) ;
    std::cout << "01/01/2010 < 01/02/2010: " << std::to_string(test) << std::endl;
    test = Date(1, 1, 2010) < Date(1, 2, 2010) ;
    std::cout << "01/01/2010 < 01/02/2010: " << std::to_string(test) << std::endl;
    test = Date(1, 2, 2010) < Date(1, 1, 2010) ;
    std::cout << "01/02/2010 < 01/01/2010: " << std::to_string(test) << std::endl;
    test = Date(1, 1, 2010) < Date(2, 1, 2010) ;
    std::cout << "01/01/2010 < 02/01/2010: " << std::to_string(test) << std::endl;
    test = Date(2, 1, 2010) < Date(1, 1, 2010) ;
    std::cout << "02/01/2010 < 01/01/2010: " << std::to_string(test) << std::endl;


    test = other_date >= end_of_world;
    std::cout << "25/12/2022 >= End of World : " << std::to_string(test) << std::endl;
    test = Date(1, 1, 2010) >= Date(1, 1, 2010);
    std::cout << "01/01/2010 >= 01/01/2010 : " << std::to_string(test) << std::endl;

    test = other_date <= end_of_world;
    std::cout << "25/12/2022 <= End of World : " << std::to_string(test) << std::endl;
    test = Date(1, 1, 2010) <= Date(1, 1, 2010);
    std::cout << "01/01/2010 <= 01/01/2010 : " << std::to_string(test) << std::endl;

    // Arithmetic
    Date new_date = end_of_world + 70;
    std::cout << "12/12/2022 + 70 days : " << new_date << std::endl;
    new_date = end_of_world + -70;
    std::cout << "12/12/2022 + -70 days : " << new_date << std::endl;
    new_date = end_of_world - 152;
    std::cout << "12/12/2022 - 152 days : " << new_date << std::endl;
    new_date = end_of_world - (-152);
    std::cout << "12/12/2022 - +152 days : " << new_date << std::endl;
    new_date = new_date + 50;
    std::cout << "12/12/2022 - 152 + 50 days : " << new_date << std::endl;

    // Incrementation
    new_date = Date(28, 02, 2022) ;
    std::cout << "new_date=" << new_date << std::endl;
    new_date++;
    std::cout << "new_date++=" << new_date << std::endl;
    new_date--;
    std::cout << "new_date--=" << new_date << std::endl;
    ++new_date;
    std::cout << "++new_date=" << new_date << std::endl;
    --new_date;
    std::cout << "--new_date=" << new_date << std::endl << std::endl;

    Date tmp;
    new_date = Date(31, 12, 2022) ;
    std::cout << "new_date = " << new_date << '\n';
    tmp = ++new_date;
    std::cout << "tmp = ++new_date -> tmp=" << tmp << " new_date=" << new_date << std::endl;
    tmp = --new_date;
    std::cout << "tmp = --new_date -> tmp=" << tmp << " new_date=" << new_date << std::endl;
    tmp = new_date++;
    std::cout << "tmp = new_date++ -> tmp=" << tmp << " new_date=" << new_date << std::endl;
    tmp = new_date--;
    std::cout << "tmp = new_date-- -> tmp=" << tmp << " new_date=" << new_date << std::endl;

    std::cout << "12/12/2022 - jour de l'annee : " << dayOfYear(new_date) << std::endl;


}

std::string generateISBN() {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> distr(0, 9);

    std::string isbn;
    for (int i = 0; i < 10; i++) {
        isbn += std::to_string(static_cast<int>(distr(eng)));
    }
    return isbn;
}

int main(int argc, char const *argv[])
{
    //testDate();
    std::vector<Writer> writers = {Writer("Musso","Guillaume",Date(06,06,1974)),
                                   Writer("Bussi","Michel",Date(29,04,1965)),
                                   Writer("Grimaldi","Virginie ",Date(01,01,1977)),
                                   Writer("Levy","Marc",Date(16,10,1961)),
                                   Writer("Valognes","Aurélie",Date(01,01,1983))};

    std::vector<Book> books = {Book("La vie est un roman",writers.at(0),Language::French,Genre::Fiction,Date(20,5,2020),"2253237647"),
                               Book("Angélique",writers.at(0),Language::French,Genre::Fiction,Date(20,9,2022),"2702183689"),
                               Book("L'Inconnue de la Seine",writers.at(0),Language::French,Genre::Drama,Date(21,9,2021),"2253106631"),
                               Book("C'est arrivé la nuit",writers.at(3),Language::French,Genre::Fiction,Date(6,5,2021),"2266315897"),
                               Book("NOA",writers.at(3),Language::French,Genre::Fiction,Date(1,5,2022),"2221243595"),
                               Book("Eteignez tout et la vie s'allume",writers.at(3),Language::French,Genre::Fiction,Date(1,5,2022),"2221268091"),
                               Book("Nouvelle Babel",writers.at(1),Language::French,Genre::Fiction,Date(3,2,2022),"2258200326"),
                               Book("Code 612 Qui a tué le petit Prince ?",writers.at(1),Language::French,Genre::Fiction,Date(14,10,2021),"2258197902")
            };

    Writer w("Flattot", "Victor", Date(16, 02, 1999));
    Book b = Book("", w, Language::French, Genre::Biography, Date(), generateISBN());
    Reader r("Flattot", "Victor");
    Reader r2("Reader2", "re");
    // Loan l(b.getISNB(),r.getId());


    Library li = Library();
    li.add(books);
    li.add(b);
    li.add(r);
    li.displayBooks(true);
    // li.displayReaders(true);


    li.loan(b, r);
    std::cout << b;
    li.returnBook(b, r2);
    std::cout << b.isBorrowed();
    li.displayLoans(true);



    return 0;
}


