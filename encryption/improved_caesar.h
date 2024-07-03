#pragma once
#include "base_caesar.h"
#include "iostream"

namespace improved_encryption {
    class ImprovedCaesar: public encryption::BaseCaesar {
    private:
        static constexpr int seed = 1234;
    public:
        static std::string encrypt(std::string userInput) ;
        static std::string decrypt(std::string encryptedMessage);
    };
}