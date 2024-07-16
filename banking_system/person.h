#pragma once

#include <string>
#include <utility>

namespace bank {
    class Person {
    public:
        Person(std::string firstName, std::string middleName, std::string lastName);

        unsigned int id;
        std::string getPersonDetails() const;
    private:
        std::string m_firstName;
        std::string m_middleName;
        std::string m_lastName;
        static unsigned int m_idCounter;
    };
}
