#pragma once
#include "test.h"
#include "../book.h"

namespace test {
    

    class BookTest : public Test {
    private:
        Book _b1;
        Book _b2;
    public:
        BookTest(const std::string &name = "DateTest", 
            Book b1 = Book("La vie est un roman", Writer("Musso", "Guillaume", Date(06, 06, 1974)), 
                           Language::French, Genre::Fiction, Date(20, 5, 2020), "2253237647"),
            Book b2 = Book("Angélique", Writer("Musso", "Guillaume", Date(06, 06, 1974)),
                           Language::French, Genre::Fiction, Date(20, 9, 2022), "2702183689"));
    };
}