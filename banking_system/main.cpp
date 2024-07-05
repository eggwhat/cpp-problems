#include <iostream>

#include "standard_account_manager.h"

int main() {
    auto manager = bank::StandardAccountManager();
    manager.createAccount("keks","keks","keks");
    while(1) {

    }
    return 0;
}
