#include <iostream>
#include "caesar.h"

int euclideanModulo(int a, int b) {
    return ((a) < 0 ? ((((a) % (b)) + (b)) % (b)) : ((a) % (b)));
}

namespace encryption {

    std::string Caesar::encrypt(std::string userInput) {
        for (char& ch: userInput) {
            ch = static_cast<char>((ch + Caesar::shift - Caesar::ascii_offset)
                % Caesar::ascii_modulo + Caesar::ascii_offset);
        }
        return userInput;
    }

    std::string Caesar::decrypt(std::string encryptedMessage) {
        for (char& ch: encryptedMessage) {
            ch = static_cast<char>((ch - Caesar::shift - Caesar::ascii_offset)
                % Caesar::ascii_modulo + Caesar::ascii_offset);
        }
        return encryptedMessage;
    }

    std::string Caesar::improvedEncrypt(std::string userInput) {
        srand(Caesar::seed);
        for (char& ch: userInput) {
            ch = static_cast<char>(euclideanModulo((ch + rand() % Caesar::ascii_offset - Caesar::ascii_offset),
                Caesar::ascii_modulo) + Caesar::ascii_offset);
        }
        return userInput;
    }

    std::string Caesar::improvedDecrypt(std::string encryptedMessage) {
        srand(Caesar::seed);
        for (char& ch: encryptedMessage) {
            ch = static_cast<char>(euclideanModulo((ch - rand() % Caesar::ascii_offset - Caesar::ascii_offset),
                Caesar::ascii_modulo) + Caesar::ascii_offset);
        }
        return encryptedMessage;
    }
}
