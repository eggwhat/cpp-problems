#pragma once

namespace encryption {

    class Caesar {
    private:
        static constexpr int shift = 5;
        static constexpr int ascii_offset = 32;
        static constexpr int ascii_modulo = 96;
        static constexpr int seed = 1234;
    public:
        static std::string encrypt(std::string userInput);
        static std::string decrypt(std::string encryptedMessage);
        static std::string improvedEncrypt(std::string userInput);
        static std::string improvedDecrypt(std::string encryptedMessage);
    };
}
