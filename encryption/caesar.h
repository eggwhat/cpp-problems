#pragma once
#include <string>
#include "i_encryption.h"

namespace encryption {

    class Caesar: public IEncryption {
    public:
        std::string encrypt(std::string const& userInput) const override;
        std::string decrypt(std::string const& encryptedMessage) const override;
    };
}
