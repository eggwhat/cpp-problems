#pragma once
#include <string>

namespace encryption {

    class IEncryption {
    protected:
        int const shift = 5;
        int const ascii_offset = 32;
        int const ascii_modulo = 96;
    public:
        virtual ~IEncryption() = default;
        virtual std::string encrypt(std::string const& userInput) = 0;
        virtual std::string decrypt(std::string const& encryptedMessage) = 0;
    };
}