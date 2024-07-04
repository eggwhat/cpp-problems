#include <iostream>
#include "caesar.h"
#include "modern_caesar.h"

int main() {
    encryption::Caesar caesarCipher;
    std::cout << "Enter a message:" << std::endl;
    std::string message;
    std::getline(std::cin, message);
    std::string encryptedMessage = caesarCipher.encrypt(message);
    std::cout << "Encrypted message in Caesar cipher:" << std::endl << encryptedMessage << std::endl;
    std::cout << "Decrypted message from Caesar cipher:" << std::endl
        << caesarCipher.decrypt(encryptedMessage) << std::endl;

    encryption::ModernCaesar modernCaesarCipher(1234);
    encryptedMessage = modernCaesarCipher.encrypt(message);
    std::cout << "Encrypted message in improved Caesar cipher:" << std::endl << encryptedMessage << std::endl;
    std::cout << "Decrypted message from improved Caesar cipher:" << std::endl
        << modernCaesarCipher.decrypt(encryptedMessage) << std::endl;
    return 0;
}
