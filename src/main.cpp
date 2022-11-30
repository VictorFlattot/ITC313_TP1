#include "date.h"
#include "book.h"
#include <iostream>

#include <random>
#include <iomanip>
#include <algorithm>

void testDate() {
    Date end_of_world(12, 12 , 2012);
    Date other_date(25, 12 , 2022);

    //Equality
    bool test = other_date == end_of_world;
    std::cout << "25/12/2022 == End of World ? " << std::to_string(test) << std::endl;
    test = other_date !=  end_of_world;
    std::cout << "25/12/2022 != End of World ? " << std::to_string(test) << std::endl;

    // Comparison
    test = other_date > end_of_world;
    std::cout << "25/12/2022 > End of World : " << std::to_string(test) << std::endl;
    test = other_date < end_of_world;
    std::cout << "25/12/2022 < End of World : " << std::to_string(test) << std::endl;
    test = other_date >= end_of_world;
    std::cout << "25/12/2022 >= End of World : " << std::to_string(test) << std::endl;
    test = other_date <= end_of_world;
    std::cout << "25/12/2022 <= End of World : " << std::to_string(test) << std::endl;

    // Arithmetic
    Date new_date = end_of_world + 70;
    std::cout << "12/12/2022 + 70 days : " << new_date << std::endl;
    new_date = end_of_world - 152;
    std::cout << "12/12/2022 - 152 days : " << new_date << std::endl;
    new_date = new_date + 50;
    std::cout << "12/12/2022 - 152 + 50 days : " << new_date << std::endl;

    // Incrementation
    new_date = Date(28, 02,2022) ;
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

}

std::string generateISBN(){
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> distr(0, 9);

    std::string isbn;
    for(int i=0; i<10; i++){
        isbn += std::to_string(static_cast<int>(distr(eng)));
    }
    return isbn;
}

int main(int argc, char const *argv[])
{
//     testDate();

    Writer w("Flattot","Victor",Date(16,02,1999));
    Book b = Book("",w,Language::French,Genre::Biography,Date(),generateISBN());
    std::cout << b << std::endl;

    return 0;
}

