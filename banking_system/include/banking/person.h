#pragma once

#include <string>
#include <utility>

#include "interfaces/i_json_serializable.h"

namespace bank {
    class Person : public banking::IJsonSerializable {
    public:
        Person(std::string firstName, std::string middleName, std::string lastName);

        unsigned int id;
        std::string getPersonDetails() const;
        virtual void Serialize(Json::Value& root );
        virtual void Deserialize(Json::Value& root);
    private:
        std::string m_firstName;
        std::string m_middleName;
        std::string m_lastName;
        static unsigned int m_idCounter;
    };
}
