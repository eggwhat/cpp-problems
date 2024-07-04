#pragma once
#include <string>

namespace bank {
    class Person {
    private:
        std::string name;
        std::string surname;
    public:
        std::string getPersonDetails();
    };
}