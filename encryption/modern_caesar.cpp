#include "modern_caesar.h"

int euclideanModulo(int const& dividend, int const& divisor) {
    return dividend < 0 ? (dividend % divisor + divisor) % divisor : dividend % divisor;
}

namespace encryption {
    std::string ModernCaesar::encrypt(std::string const& userInput) {
        srand(seed);
        std::string encryptedMessage;
        for (char const& ch: userInput) {
            encryptedMessage += static_cast<char>(euclideanModulo((ch + rand() % ascii_offset - ascii_offset),
                ascii_modulo) + ascii_offset);
        }
        return encryptedMessage;
    }

    std::string ModernCaesar::decrypt(std::string const& encryptedMessage) {
        srand(seed);
        std::string decryptedMessage;
        for (char const& ch: encryptedMessage) {
            decryptedMessage += static_cast<char>(euclideanModulo((ch - rand() % ascii_offset - ascii_offset),
                ascii_modulo) + ascii_offset);
        }
        return decryptedMessage;
    }
}
