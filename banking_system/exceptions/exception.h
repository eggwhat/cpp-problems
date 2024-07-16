#pragma once

#include <exception>
#include <string>

namespace exceptions {
    class Exception: public std::exception {
    public:
        explicit Exception(std::string const& message);
        char const* what() const noexcept override;
    private:
        std::string m_message;
    };
}
