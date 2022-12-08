#include "dateTest.h"

namespace test {
    DateTest::DateTest(const std::string &name, Date d1, Date d2) : Test(name), _d1(d1), _d2(d2) {};

    void DateTest::equality() {
        std::cout << "==============================" << std::endl;
        std::cout << "      Test Date Equality" << std::endl;
        std::cout << "==============================" << std::endl;

        _d3 = Date(_d2.getDay(), _d2.getMonth(), _d2.getYear());
        std::cout << std::boolalpha;

        bool test = _d1 == _d2;
        std::cout << _d1 << " == " << _d2 << " ? " << test << std::endl;

        test = _d1 != _d2;
        std::cout << _d1 << " != " << _d2 << " ? " << test << std::endl;

        test = _d2 == _d3;
        std::cout << _d2 << " == " << _d3 << " ? " << test << std::endl << std::endl;
    }

    void DateTest::comparison() {
        std::cout << "==============================" << std::endl;
        std::cout << "     Test Date Comparison" << std::endl;
        std::cout << "==============================" << std::endl;

        _d3 = Date(10, 5, 2010);
        bool test = _d3 < _d3;
        std::cout << _d3 << " < " << _d3 << " ? " << test << std::endl;

        _d4 = Date(10, 8, 2010);
        test = _d3 < _d4;
        std::cout << _d3 << " < " << _d4 << " ? " << test << std::endl;

        _d4 = Date(10, 5, 2011);
        test = _d3 < _d4;
        std::cout << _d3 << " < " << _d4 << " ? " << test << std::endl;

        _d4 = Date(10, 4, 2010);
        test = _d3 < _d4;
        std::cout << _d3 << " < " << _d4 << " ? " << test << std::endl;

        _d4 = Date(15, 5, 2010);
        test = _d3 < _d4;
        std::cout << _d3 << " < " << _d4 << " ? " << test << std::endl << std::endl;


        _d3 = Date(10, 8, 2010);
        test = _d3 > _d3;
        std::cout << _d3 << " > " << _d3 << " ? " << test << std::endl;

        _d4 = Date(10, 5, 2011);
        test = _d3 > _d4;
        std::cout << _d3 << " > " << _d4 << " ? " << test << std::endl;

        _d4 = Date(10, 4, 2011);
        test = _d3 > _d4;
        std::cout << _d3 << " > " << _d4 << " ? " << test << std::endl;


        _d4 = Date(10, 5, 2008);
        test = _d3 > _d4;
        std::cout << _d3 << " > " << _d4 << " ? " << test << std::endl << std::endl;

        test = _d3 >= _d4;
        std::cout << _d3 << " >= " << _d4 << " ? " << test << std::endl;
        test = _d3 >= _d3;
        std::cout << _d3 << " >= " << _d4 << " ? " << test << std::endl << std::endl;

        test = _d3 <= _d4;
        std::cout << _d3 << " <= " << _d4 << " ? " << test << std::endl;
        test = _d3 <= _d3;
        std::cout << _d3 << " <= " << _d4 << " ? " << test << std::endl << std::endl;
    }

    void DateTest::arithmetic() {
        std::cout << "==============================" << std::endl;
        std::cout << "     Test Date Arithmetic" << std::endl;
        std::cout << "==============================" << std::endl;

        _d3 = _d1 + 70;
        std::cout << _d1 << " + 70 days : " << _d3 << std::endl;

        _d3 = _d1 + -70;
        std::cout << _d1 << " + -70 days : " << _d3 << std::endl;

        _d3 = _d1 - 152;
        std::cout << _d1 << " - 152 days : " << _d3 << std::endl;

        _d3 = _d1 - (-152);
        std::cout << _d1 << " - +152 days : " << _d3 << std::endl;

        _d3 = _d1 + 50;
        std::cout << _d1 << " - 152 + 50 days : " << _d3 << std::endl;

        _d3 = Date(1, 1, 2010);
        _d4 = _d3 - 7;
        std::cout << _d3 << " - 7 days : " << _d4 << std::endl;
    }

    void DateTest::incrementation() {
        std::cout << "==============================" << std::endl;
        std::cout << "   Test Date Incrementation" << std::endl;
        std::cout << "==============================" << std::endl;

        _d3 = Date(28, 02, 2022);
        std::cout << "new_date = " << _d3 << std::endl;
        _d3++;
        std::cout << "new_date++ = " << _d3 << std::endl;
        _d3--;
        std::cout << "new_date-- = " << _d3 << std::endl;
        ++_d3;
        std::cout << "++new_date = " << _d3 << std::endl;
        --_d3;
        std::cout << "--new_date = " << _d3 << std::endl << std::endl;


        _d3 = Date(31, 12, 2022);
        std::cout << "new_date = " << _d3 << '\n';
        _d4 = ++_d3;
        std::cout << "tmp = ++new_date -> tmp=" << _d4 << " new_date = " << _d3 << std::endl;
        _d4 = --_d3;
        std::cout << "tmp = --new_date -> tmp=" << _d4 << " new_date = " << _d3 << std::endl;
        _d4 = _d3++;
        std::cout << "tmp = new_date++ -> tmp=" << _d4 << " new_date = " << _d3 << std::endl;
        _d4 = _d3--;
        std::cout << "tmp = new_date-- -> tmp=" << _d4 << " new_date = " << _d3 << std::endl << std::endl;
    }

    void DateTest::miscellaneous() {
        std::cout << "==============================" << std::endl;
        std::cout << "   Test Date Miscellaneous" << std::endl;
        std::cout << "==============================" << std::endl;

        _d3 = Date(12, 12, 2022);
        std::cout << _d3 << " = Day of year : " << dayOfYear(_d3) << std::endl;

        _d3 = Date();
        _d3.setYear(2020);
        _d3.setMonth(6);
        _d3.setDay(4);

        //_d3.setYear(-2020);   // Test assert false
        //_d3.setMonth(-6);     // Test assert false
        //_d3.setDay(-4);       // Test assert false

        std::cout << Date() << " set for Jun/9,2020 : " << _d3 << std::endl << std::endl;
    }

    void DateTest::all() {
        equality();
        comparison();
        arithmetic();
        incrementation();
        miscellaneous();
    }
}