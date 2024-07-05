#pragma once
#include <string>
#include "i_encryption.h"

namespace encryption {

    class ModernCaesar: public IEncryption {
    private:
        int const seed;
    public:
        explicit ModernCaesar(int _seed)
            : seed(_seed) {
        }
        std::string encrypt(std::string const& userInput) override;
        std::string decrypt(std::string const& encryptedMessage) override;
    };
}
