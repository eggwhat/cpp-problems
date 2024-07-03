#include <iostream>
#include "caesar.h"

int main() {
    std::cout << "Enter a message:" << std::endl;
    std::string message;
    std::getline(std::cin, message);
    std::string encryptedMessage = encryption::Caesar::encrypt(message);
    std::cout << "Encrypted message:" << std::endl << encryptedMessage << std::endl;
    std::cout << "Decrypted message:" << std::endl << encryption::Caesar::decrypt(encryptedMessage) << std::endl;
    return 0;
}
