#include <banking/person.h>

namespace bank {

    Person::Person(std::string firstName, std::string middleName, std::string lastName, unsigned int const id) :
            m_id(id), m_firstName(std::move(firstName)),
            m_middleName(std::move(middleName)), m_lastName(std::move(lastName)) {

    }

    std::string Person::getPersonDetails() const {
        return !m_middleName.empty() ? m_firstName + " " + m_middleName + " " + m_lastName :
        m_firstName + " " + m_lastName;
    }

    void Person::serialize(Json::Value& root) {
        root["firstName"] = m_firstName;
        root["middleName"] = m_middleName;
        root["lastName"] = m_lastName;
    }

    void Person::deserialize(Json::Value const& root) {
        m_firstName = root.get("firstName", "").asString();
        m_middleName = root.get("middleName", "").asString();
        m_lastName = root.get("lastName", "").asString();
    }
} // bank
