#include <iostream>
#include <cmath>

double calculateMinimalValue(int size) {
    return -std::pow(2,size)/2;
}

int main() {
    int const bitsInByte = 8;

    char charMin = static_cast<char>(calculateMinimalValue(sizeof(char) * bitsInByte));
    std::cout << "Minimal value of char: " << +charMin << std::endl;
    char charLowerThanMin = charMin - 1;
    std::cout << "Confirmation: charMin - 1 = " << +charLowerThanMin << std::endl;

    auto shortMin = static_cast<short>(calculateMinimalValue(sizeof(short) * bitsInByte));
    std::cout << "Minimal value of short: " << shortMin << std::endl;
    short shortLowerThanMin = shortMin - 1;
    std::cout << "Confirmation: shortMin - 1 = " << shortLowerThanMin << std::endl;

    auto intMin = static_cast<int>(calculateMinimalValue(sizeof(int) * bitsInByte));
    std::cout << "Minimal value of int: " << intMin << std::endl;
    int intLowerThanMin = intMin - 1;
    std::cout << "Confirmation: intMin - 1 = " << intLowerThanMin << std::endl;

    return 0;
}
