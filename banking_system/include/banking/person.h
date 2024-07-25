#pragma once

#include <string>
#include <utility>

#include "interfaces/i_json_serializable.h"

namespace bank {
    class Person : public banking::IJsonSerializable {
    public:
        Person(std::string firstName, std::string middleName, std::string lastName, unsigned int id = 0);

        unsigned int const m_id;

        std::string getPersonDetails() const;
        void serialize(Json::Value& root) override;
        void deserialize(Json::Value const& root) override;
    private:
        std::string m_firstName;
        std::string m_middleName;
        std::string m_lastName;
    };
}
