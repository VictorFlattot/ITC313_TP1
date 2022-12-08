//
// Created by Shadow on 08/12/2022.
//
#include "test.h"

#include <utility>

namespace test {
    Test::Test(std::string name) : _name(std::move(name)){}

    const std::string &Test::getName() const { return _name; }
    void Test::setName(const std::string &name) { _name = name; }

}
