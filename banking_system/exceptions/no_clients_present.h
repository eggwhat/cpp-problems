#pragma once

#include <exception>

namespace exceptions {
    class NoClientsPresent: public std::exception {
    public:
        explicit NoClientsPresent() = default;
        char const* what() const noexcept override { return "There are no clients present."; }
    };
}
