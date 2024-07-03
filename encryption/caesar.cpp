#include <iostream>
#include "caesar.h"

namespace encryption {

    std::string Caesar::encrypt(std::string userInput) {
        for (char& ch: userInput) {
            ch = static_cast<char>((ch + Caesar::shift) % Caesar::ascii_modulo);
        }
        return userInput;
    }
}
