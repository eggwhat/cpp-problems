#include "improved_caesar.h"

namespace encryption {
    std::string ImprovedCaesar::encrypt(std::string userInput) {
        srand(ImprovedCaesar::seed);
        for (char& ch: userInput) {
            ch = static_cast<char>((ch + rand() - ImprovedCaesar::ascii_offset)
                % ImprovedCaesar::ascii_modulo + ImprovedCaesar::ascii_offset);
        }
    }

    std::string ImprovedCaesar::decrypt(std::string encryptedMessage) {
        srand(ImprovedCaesar::seed);
        for (char& ch: encryptedMessage) {
            ch = static_cast<char>((ch - rand() - ImprovedCaesar::ascii_offset)
                % ImprovedCaesar::ascii_modulo + ImprovedCaesar::ascii_offset);
        }
    }


} // encryption