#pragma once

#include <string>

namespace bank {
    class Person {
    private:
        std::string firstName;
        std::string middleName;
        std::string lastName;
    public:
        std::string getPersonDetails();
    };
}