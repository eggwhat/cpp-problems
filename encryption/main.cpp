#include <iostream>
#include "caesar.h"

int main() {
    std::cout << "Enter a message:" << std::endl;
    std::string message;
    std::getline(std::cin, message);
    std::string encryptedMessage = encryption::Caesar::encrypt(message);
    std::cout << "Encrypted message in Caesar cipher:" << std::endl << encryptedMessage << std::endl;
    std::cout << "Decrypted message from Caesar cipher:" << std::endl
        << encryption::Caesar::decrypt(encryptedMessage) << std::endl;
    encryptedMessage = encryption::Caesar::improvedEncrypt(message);
    std::cout << "Encrypted message in improved Caesar cipher:" << std::endl << encryptedMessage << std::endl;
    std::cout << "Decrypted message from improved Caesar cipher:" << std::endl
        << encryption::Caesar::improvedDecrypt(encryptedMessage) << std::endl;
    return 0;
}
