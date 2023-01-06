#pragma once

#include "test.h"
#include "../writer.h"

namespace test {

    class WriterTest : public Test {
    private:
        Writer _w1;
        Writer _w2;
    public:
        WriterTest(const std::string &name = "DateTest", 
                Writer w1 = Writer("Musso", "Guillaume", Date(06, 06, 1974)),
                Writer w2 = Writer("Bussi","Michel",Date(29,04,1965)));

    };
}