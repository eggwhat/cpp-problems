#include <iostream>
#include "caesar.h"

int main() {
    std::cout << "Enter a message:" << std::endl;
    std::string message, encryptedMessage;
    std::cin >> message;
    encryptedMessage = encryption::Caesar::encrypt(message);
    std::cout << encryptedMessage << std::endl;
    return 0;
}
