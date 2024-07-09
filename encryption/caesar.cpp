#include <iostream>
#include <string>

#include "caesar.h"

namespace encryption {

    std::string Caesar::encrypt(std::string const& userInput) const {
        std::string encryptedMessage;
        for (char const& ch: userInput) {
            encryptedMessage += static_cast<char>((ch + shift - ascii_offset)
                % ascii_modulo + ascii_offset);
        }
        return encryptedMessage;
    }

    std::string Caesar::decrypt(std::string const& encryptedMessage) const {
        std::string decryptedMessage;
        for (char const& ch: encryptedMessage) {
            decryptedMessage += static_cast<char>((ch - shift - ascii_offset)
                % ascii_modulo + ascii_offset);
        }
        return decryptedMessage;
    }
}
