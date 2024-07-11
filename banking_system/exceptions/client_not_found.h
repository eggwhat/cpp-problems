#pragma once

#include <exception>

namespace exceptions {
    class ClientNotFound: public std::exception {
    public:
        explicit ClientNotFound() = default;
        char const* what() const noexcept override { return "You don't have that much money!"; }
    };
}
