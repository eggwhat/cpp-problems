#include "caesar.h"

namespace encryption {
    class ImprovedCaesar: public BaseCaesar {
    private:
        static constexpr int seed = 1234;

    public:
        static std::string encrypt(std::string userInput) ;
        static std::string decrypt(std::string encryptedMessage);
    };
}