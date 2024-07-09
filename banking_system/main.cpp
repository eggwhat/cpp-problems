#include <iostream>
#include <string>

#include "maintenance.h"
#include "premium_account_manager.h"
#include "premium_account_manager_factory.h"
#include "standard_account_manager.h"
#include "standard_account_manager_factory.h"

void createNewClientProfile(bank::Maintenance& maintenance) {
    std::string firstName, middleName, lastName;
    std::cout << "Provide a first name:" << std::endl;
    std::cin >> firstName;
    std::cout << "Provide a middle name:" << std::endl;
    std::cin >> middleName;
    std::cout << "Provide a last name:" << std::endl;
    std::cin >> lastName;
    maintenance.addClient(std::make_shared<bank::Person>(firstName, middleName, lastName));
}

void chooseClient(bank::Maintenance& maintenance, bank::StandardAccountManagerFactory& standardAccountManagerFactory,
        bank::PremiumAccountManagerFactory& premiumAccountManagerFactory) {
    std::cout << "Choose a client:" << std::endl;
    maintenance.listClients();
    unsigned int clientId;
    std::cin >> clientId;

    int clientOption;
    std::cout << "Choose an option: " << std::endl;
    std::cout << "1) create a new account: " << std::endl;
    std::cout << "2) choose an account: " << std::endl;
    std::cin >> clientOption;
    switch (clientOption) {
        case 1: {
            auto client = maintenance.getClient(clientId);
            int isPremiumAccount;
            std::cout << "Premium account (yes=0):" << std::endl;
            std::cin >> isPremiumAccount;
            auto manager = isPremiumAccount == 0 ? premiumAccountManagerFactory.createManager()
                : standardAccountManagerFactory.createManager();
            maintenance.addAccount(manager->createAccount(client));
            break;
        }
        case 2: {
            std::cout << "Client accounts: " << std::endl;
            auto accounts = maintenance.findClientAccounts(clientId);
            bank::Maintenance::listClientAccount(accounts);
            std::cout << "Choose account: " << std::endl;
            unsigned int accountIndex;
            std::cin >> accountIndex;
            auto account = accounts[accountIndex];
            auto manager = bank::Maintenance::createAccountManager(account);
            std::cout << manager->getAccountDetails(account) << std::endl;
            break;
        }
        default:
            break;
    }
}

int main() {
    int option;

    auto maintenance = bank::Maintenance();
    auto standardAccountManagerFactory = bank::StandardAccountManagerFactory();
    auto premiumAccountManagerFactory = bank::PremiumAccountManagerFactory();
    while(1) {
        std::cout << "Choose an option: " << std::endl;
        std::cout << "1) create new client profile: " << std::endl;
        std::cout << "2) list all clients: " << std::endl;
        std::cout << "3) quit " << std::endl;
        std::cin >> option;

        switch (option) {
            case 1:
                createNewClientProfile(maintenance);
                break;
            case 2:
                chooseClient(maintenance, standardAccountManagerFactory, premiumAccountManagerFactory);
                break;
            case 3:
                return 0;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
}
