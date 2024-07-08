#pragma once

#include <string>
#include <utility>

namespace bank {
    class Person {
    private:
        std::string m_firstName;
        std::string m_middleName;
        std::string m_lastName;
    public:
        Person(std::string firstName, std::string middleName, std::string lastName):
            m_firstName(std::move(firstName)), m_middleName(std::move(middleName)),
            m_lastName(std::move(lastName)) {}

        std::string getPersonDetails() const;
    };
}
