#include <iostream>
#include <string>
#include "caesar.h"
#include "modern_caesar.h"

void performEncryption(encryption::IEncryption const& cipher, std::string const& message) {
    std::string encryptedMessage = cipher.encrypt(message);
    std::cout << "encrypted message:" << std::endl << encryptedMessage << std::endl;
    std::cout << "decrypted message:" << std::endl << cipher.decrypt(encryptedMessage) << std::endl;
}

int main() {
    std::cout << "Enter a message:" << std::endl;
    std::string message;
    std::getline(std::cin, message);

    std::cout << "Classic Caesar:" << std::endl;
    encryption::Caesar caesarCipher;
    performEncryption(caesarCipher, message);

    std::cout << "Modern Caesar:" << std::endl;
    encryption::ModernCaesar modernCaesarCipher(1234);
    performEncryption(modernCaesarCipher, message);

    return 0;
}
