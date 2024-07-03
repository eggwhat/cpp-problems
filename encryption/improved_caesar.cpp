#include "improved_caesar.h"

int euclideanModulo(int a, int b) {
    return ((a) < 0 ? ((((a) % (b)) + (b)) % (b)) : ((a) % (b)));
}

namespace improved_encryption {
    std::string ImprovedCaesar::encrypt(std::string userInput) {
        srand(ImprovedCaesar::seed);
        for (char& ch: userInput) {
            ch = static_cast<char>(euclideanModulo((ch + rand() % ImprovedCaesar::ascii_offset - ImprovedCaesar::ascii_offset),
                ImprovedCaesar::ascii_modulo) + ImprovedCaesar::ascii_offset);
        }
        return userInput;
    }

    std::string ImprovedCaesar::decrypt(std::string encryptedMessage) {
        srand(ImprovedCaesar::seed);
        for (char& ch: encryptedMessage) {
            ch = static_cast<char>(euclideanModulo((ch - rand() % ImprovedCaesar::ascii_offset - ImprovedCaesar::ascii_offset),
                ImprovedCaesar::ascii_modulo) + ImprovedCaesar::ascii_offset);
        }
        return encryptedMessage;
    }


} // encryption