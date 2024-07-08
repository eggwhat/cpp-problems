#include <iostream>
#include <string>

#include "maintenance.h"
#include "premium_account_manager.h"
#include "standard_account_manager.h"

void createNewAccount() {
    std::string firstName, middleName, lastName, isPremiumAccount;
    std::cout << "Provide a first name:" << std::endl;
    std::cin >> firstName;
    std::cout << "Provide a middle name:" << std::endl;
    std::cin >> middleName;
    std::cout << "Provide a last name:" << std::endl;
    std::cin >> lastName;
    std::cout << "Premium account (yes/no):" << std::endl;
    std::cin >> isPremiumAccount;
    switch (isPremiumAccount) {
        case "yes":
            auto premiumAccountManager = bank::PremiumAccountManager();

            break;
        case "no":
            auto standardAccountManager = bank::StandardAccountManager();
            auto account = standardAccountManager.createAccount("keks","keks","keks");
            break;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
    }
}

void chooseClient(bank::Maintenance const& maintenance) {
    std::cout << "Choose a client:" << std::endl;
    maintenance.listClients();
}

int main() {
    int option;

    auto maintenance = bank::Maintenance();
    while(1) {
        std::cout << "Choose an option: " << std::endl;
        std::cout << "1) create new account: " << std::endl;
        std::cout << "2) list all clients: " << std::endl;
        std::cin >> option;

        switch (option) {
            case 1:
                createNewAccount();
                break;
            case 2:
                chooseClient(maintenance);
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
    return 0;
}
