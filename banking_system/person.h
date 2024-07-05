#pragma once

#include <string>
#include <utility>

namespace bank {
    class Person {
    private:
        std::string firstName;
        std::string middleName;
        std::string lastName;
    public:
        Person(std::string _firstName, std::string _middleName, std::string _lastName):
            firstName(std::move(_firstName)), middleName(std::move(_middleName)),
            lastName(std::move(_lastName)) {}

        std::string getPersonDetails();
    };
}
