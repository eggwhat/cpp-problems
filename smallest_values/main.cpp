#include <iostream>
#include <cmath>
#include <limits>

double calculateMinimalValue(int const& size) {
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

    unsigned char uCharMin = 0;
    std::cout << "Minimal value of unsigned char: " << +uCharMin << std::endl;
    uCharMin = uCharMin - 1;
    std::cout << "Confirmation: uCharMin - 1 = " << +(uCharMin) << std::endl;

    unsigned short uShortMin = 0;
    std::cout << "Minimal value of unsigned short: " << uShortMin << std::endl;
    uShortMin = uShortMin - 1;
    std::cout << "Confirmation: uShortMin - 1 = " << uShortMin << std::endl;

    unsigned int uIntMin = 0;
    std::cout << "Minimal value of unsigned int: " << uIntMin << std::endl;
    std::cout << "Confirmation: uIntMin - 1 = " << uIntMin - 1 << std::endl;

    //int const floatingPointBase = 2;

    //int const floatMaxExponent = std::numeric_limits<float>::max_exponent;
    //int const floatMantissaLength = std::numeric_limits<float>::digits;
    float const floatMin = -std::numeric_limits<float>::max();
    std::cout << "Smallest float: " << floatMin << std::endl;

    //int const doubleMaxExponent = std::numeric_limits<double>::max_exponent;
    //int const doubleMantissaLength = std::numeric_limits<double>::digits;
    double const doubleMin = -std::numeric_limits<double>::max();
    std::cout << "Smallest double: " << doubleMin << std::endl;

    //int const longDoubleMaxExponent = std::numeric_limits<long double>::max_exponent;
    //int const longDoubleMantissaLength = std::numeric_limits<long double>::digits;
    long double const longDoubleMin = -std::numeric_limits<long double>::max();
    std::cout << "Smallest long double: " << longDoubleMin << std::endl;

    char* charPointerMin = new char(static_cast<char>(calculateMinimalValue(sizeof(char) * bitsInByte)));
    std::cout << "Minimal value of char pointer: " << +*charPointerMin << std::endl;
    *charPointerMin -= 1;
    std::cout << "Confirmation: charPointer - 1 = " << +*charPointerMin << std::endl;
    delete charPointerMin;

    auto intPointerMin = new int(static_cast<int>(calculateMinimalValue(sizeof(int) * bitsInByte)));
    std::cout << "Minimal value of int pointer: " << *intPointerMin << std::endl;
    *intPointerMin -= 1;
    std::cout << "Confirmation: intMin - 1 = " << *intPointerMin << std::endl;
    delete intPointerMin;

    void* voidPointer = &charMin;
    std::cout << "Minimal value of void pointer as short: " << +*static_cast<char*>(voidPointer) << std::endl;
    *static_cast<char*>(voidPointer) -= 1;
    std::cout << "Confirmation: " << +*static_cast<char*>(voidPointer) << std::endl;

    voidPointer = &intMin;
    std::cout << "Minimal value of void pointer as int: " << +*static_cast<int*>(voidPointer) << std::endl;
    *static_cast<int*>(voidPointer) -= 1;
    std::cout << "Confirmation: " << +*static_cast<int*>(voidPointer) << std::endl;

    return 0;
}
