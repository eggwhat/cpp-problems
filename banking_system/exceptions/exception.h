#pragma once

#include <exception>
#include <string>

namespace exceptions {
    class Exception: public std::exception {
    public:
        explicit Exception() :m_message( "Exception raised! Details: ") {}
        char const* what() const noexcept override { return m_message.c_str(); }
    protected:
        std::string m_message;
    };
}
