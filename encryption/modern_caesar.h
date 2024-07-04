#pragma once
#include <string>
#include "i_encryption.h"

namespace encryption {

    class ModernCaesar: public IEncryption {
    private:
        int const seed;
    public:
        explicit ModernCaesar(int seed)
            : seed(seed) {
        }
        ~ModernCaesar() override = default;

        std::string encrypt(std::string const& userInput) override;
        std::string decrypt(std::string const& encryptedMessage) override;
    };
}
