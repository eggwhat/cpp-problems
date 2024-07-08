#include "person.h"

namespace bank {
    std::string Person::getPersonDetails() const {
        return !m_middleName.empty() ? m_firstName + " " + m_middleName + " " + m_lastName :
        m_firstName + " " + m_lastName;
    }

} // bank
