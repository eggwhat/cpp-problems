#include <iostream>

namespace encryption {

    class Caesar {
    private:
        static constexpr int shift = 3;
        static constexpr int ascii_offset = 32;
        static constexpr int ascii_modulo = 96;
    public:
        static std::string encrypt(std::string userInput);
        static std::string decrypt(std::string encryptedMessage);
    };
}
