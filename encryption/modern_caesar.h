#pragma once
#include <string>
#include "i_encryption.h"

namespace encryption {

    class ModernCaesar: public IEncryption {
    private:
        int const m_seed;
    public:
        explicit ModernCaesar(int seed)
            : m_seed(seed) {
        }
        std::string encrypt(std::string const& userInput) const override;
        std::string decrypt(std::string const& encryptedMessage) const override;
    };
}
