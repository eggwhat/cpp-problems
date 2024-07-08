#include "person.h"

namespace bank {
    Person::Person(std::string firstName, std::string middleName, std::string lastName):
            m_firstName(std::move(firstName)), m_middleName(std::move(middleName)),
            m_lastName(std::move(lastName)), id{m_idCounter++} {}

    unsigned int Person::m_idCounter = 0;

    std::string Person::getPersonDetails() const {
        return !m_middleName.empty() ? m_firstName + " " + m_middleName + " " + m_lastName :
        m_firstName + " " + m_lastName;
    }

} // bank
