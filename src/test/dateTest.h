#pragma once

#include "test.h"
#include "../date.h"

namespace test {
    class DateTest : public Test {
    private:
        Date _d1;
        Date _d2;
        Date _d3;
        Date _d4;
    public:
        explicit DateTest(const std::string &name = "DateTest", Date d1 = Date(12, 12 , 2012),
                          Date d2 = Date(25, 12, 2022));
        void equality();
        void comparison();
        void arithmetic();
        void incrementation();
        void miscellaneous();
        void all();

    };

} // test

