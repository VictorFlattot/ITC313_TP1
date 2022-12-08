//
// Created by Shadow on 08/12/2022.
//
#include <string>
#include <iostream>


#pragma once
namespace test {
    class Test {
    private:
        std::string _name;
    public:

        explicit Test(std::string name = "Test");

        const std::string &getName() const;

        void setName(const std::string &name);
    };
}


