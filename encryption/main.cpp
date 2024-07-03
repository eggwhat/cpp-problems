#include <iostream>
#include "caesar.h"

int main() {
    std::cout << "Enter a message:" << std::endl;
    std::string message;
    std::cin >> message;
    std::string encryptedMessage = encryption::Caesar::encrypt(message);
    std::cout << encryptedMessage << std::endl;
    return 0;
}
