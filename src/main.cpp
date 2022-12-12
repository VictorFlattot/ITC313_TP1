#include "library.h"
#include "test/dateTest.h"
#include "test/bookTest.h"
#include "test/writerTest.h"
#include <random>
#include <algorithm>
// 
void foo();



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

void foo() {
    std::vector<Writer> writers = {Writer("Musso", "Guillaume", Date(06, 06, 1974)),
                                   Writer("Bussi","Michel",Date(29,04,1965)),
                                   Writer("Grimaldi","Virginie ",Date(01,01,1977)),
                                   Writer("Levy","Marc",Date(16,10,1961)),
                                   Writer("Valognes","Aurélie",Date(01,01,1983))};

    std::vector<Book> books = {Book("La vie est un roman", writers.at(0), French, Genre::Fiction, Date(20, 5, 2020), "2253237647"),
                               Book("Angélique", writers.at(0), French, Genre::Fiction, Date(20, 9, 2022), "2702183689"),
                               Book("L'Inconnue de la Seine", writers.at(0), French, Genre::Drama, Date(21, 9, 2021), "2253106631"),
                               Book("C'est arrivé la nuit", writers.at(3), French, Genre::Fiction, Date(6, 5, 2021), "2266315897"),
                               Book("NOA", writers.at(3), French, Genre::Fiction, Date(1, 5, 2022), "2221243595"),
                               Book("Eteignez tout et la vie s'allume", writers.at(3), French, Genre::Fiction, Date(1, 5, 2022), "2221268091"),
                               Book("Nouvelle Babel", writers.at(1), French, Genre::Fiction, Date(3, 2, 2022), "2258200326"),
                               Book("Code 612 Qui a tué le petit Prince ?", writers.at(1), French, Genre::Fiction, Date(14, 10, 2021), "2258197902")
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
}

int main(int argc, char const *argv[])
{
    //dateTest();
    // foo();
    // test::DateTest dateTest = test::DateTest();
    // dateTest.all();

    test::WriterTest writerTest = test::WriterTest();

    return 0;
}


