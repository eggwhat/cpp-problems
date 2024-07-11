#pragma once

#include <exception>

namespace exceptions {
    class NoAccountFoundForGivenClientId: public std::exception {
    public:
        explicit NoAccountFoundForGivenClientId() = default;
        char const* what() const noexcept override { return "There are no account for client with given id."; }
    };
}
