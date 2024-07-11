#pragma once

#include <exception>
#include <string>

namespace exceptions {
    class InvalidPersonDataEntry: public std::exception {
    public:
        explicit InvalidPersonDataEntry(std::string const& fieldName) :
            m_message( "Required filled is empty: " + fieldName) {}
        char const* what() const noexcept override { return m_message.c_str(); }
    private:
        std::string m_message;
    };
}
