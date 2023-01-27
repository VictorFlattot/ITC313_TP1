#include "library.h"
#include "test/dateTest.h"
#include <random>
#include <algorithm>


template<typename T>
void f(T s)
{
    std::cout << s << '\n';
}

int main(int argc, char const *argv[])
{
    bool activeTest = false;
    if (activeTest) {
        if (true){
            test::DateTest dateTest = test::DateTest();
            dateTest.all();
        }
    }

    std::vector<Writer> writers = {Writer("Musso", "Guillaume", Date(06, 06, 1974)),
                                   Writer("Bussi","Michel",Date(29,04,1965)),
                                   Writer("Grimaldi","Virginie ",Date(01,01,1977)),
                                   Writer("Levy","Marc",Date(16,10,1961)),
                                   Writer("Valognes","Aurélie",Date(01,01,1983))};

    std::vector<Book> books = {Book("La vie est un roman", writers.at(0), French, Genre::Fiction, Date(20, 5, 2020), "2253237647"),
                               Book("Angélique", writers.at(0), French, Genre::Fiction, Date(20, 9, 2022), "2702183689"),
                               Book("L'Inconnue de la Seine", writers.at(0), French, Genre::Drama, Date(21, 9, 2021), "2253106631"),
                               Book("Nouvelle Babel", writers.at(1), French, Genre::Fiction, Date(3, 2, 2022), "2258200326"),
                               Book("Code 612 Qui a tué le petit Prince ?", writers.at(1), French, Genre::Fiction, Date(14, 10, 2021), "2258197902"),
                               Book("Il nous restera", writers.at(2), French, Genre::Fiction, Date(4, 5, 2022), "2213717087"),
                               Book("Et que ne durent que les moments doux", writers.at(2), French, Genre::Fiction, Date(12, 5, 2021), "2253241954"),
                               Book("C'est arrivé la nuit", writers.at(3), French, Genre::Fiction, Date(6, 5, 2021), "2266315897"),
                               Book("NOA", writers.at(3), French, Genre::Fiction, Date(1, 5, 2022), "2221243595"),
                               Book("Eteignez tout et la vie s'allume", writers.at(3), French, Genre::Fiction, Date(1, 5, 2022), "2221268091"),
                               Book("Le parfum du bonheur est plus fort sous la pluie", writers.at(3), French, Genre::Fiction, Date(2, 5, 2018), "2253088110"),
                               Book("La Ritournelle", writers.at(4), French, Genre::Fiction, Date(2, 3, 2022), "2213720541"),
                               Book("Né sous une bonne étoile Broché", writers.at(4), French, Genre::Fiction, Date(31, 3, 2021), "2213720541"),
                               Book("Le tourbillon de la vie", writers.at(4), French, Genre::Fiction, Date(2, 3, 2022), "2253100485")
    };

    std::vector<Reader> readers = {Reader("Flattot", "Victor"),
                                   Reader("Dupont", "Michel"),
                                   Reader("Martin", "Jacques")};


    Library li = Library();
    li.add(books);
    li.add(readers);
    li.displayBooks(true);
    // li.displayReaders(true);


    li.loan(books.at(0), readers.at(0));
    std::cout << books.at(0);
    li.loan(books.at(0), readers.at(1));
    li.returnBook(books.at(0), readers.at(0));
    //std::cout << books.at(0).isBorrowed();
    //li.displayLoans(true);
    std::cout << books.at(0);
    
    return 0;
}


