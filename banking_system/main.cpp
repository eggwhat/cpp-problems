#include <iostream>
#include <string>

#include "maintenance.h"
#include "premium_account_manager.h"
#include "standard_account_manager.h"

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

void chooseClient(bank::Maintenance& maintenance) {
    std::cout << "Choose a client:" << std::endl;
    maintenance.listClients();
    unsigned int clientId;
    std::cin >> clientId;
    std::cout << "Client accounts: " << std::endl;
    auto accounts = maintenance.findClientAccounts(clientId);
    int clientOption;
    bank::Maintenance::listClientAccount(accounts);
    std::cout << "Choose account: " << std::endl;
    unsigned int accountIndex;
    std::cin >> accountIndex;
    auto account = accounts[accountIndex];
}

int main() {
    int option;

    auto maintenance = bank::Maintenance();
    while(1) {
        std::cout << "Choose an option: " << std::endl;
        std::cout << "1) create new client profile: " << std::endl;
        std::cout << "2) list all clients: " << std::endl;
        std::cin >> option;

        switch (option) {
            case 1:
                createNewClientProfile(maintenance);
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
