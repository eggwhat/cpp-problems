#pragma once

#include <exception>

namespace exceptions {
    class NotEnoughFunds: public std::exception {
    public:
        explicit NotEnoughFunds() = default;
        char const* what() const noexcept override { return "You don't have that much money."; }
    };
}
