#include <iostream>
#include "base_caesar.h"

namespace encryption {

    class Caesar: public BaseCaesar{
    public:
        static std::string encrypt(std::string userInput);
        static std::string decrypt(std::string encryptedMessage);
    };
}
