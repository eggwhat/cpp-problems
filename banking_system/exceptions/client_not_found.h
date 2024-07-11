#pragma once

#include <exception>

namespace exceptions {
    class ClientNotFound: public std::exception {
    public:
        explicit ClientNotFound() = default;
        char const* what() const noexcept override { return "Client with given ID does not exist."; }
    };
}
