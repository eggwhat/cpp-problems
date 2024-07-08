#include <iostream>

#include "standard_account_manager.h"

int main() {
    auto manager = bank::StandardAccountManager();
    auto account = manager.createAccount("keks","keks","keks");
    std::cout << account->getDetails() << std::endl;
    while(1) {

    }
    return 0;
}
