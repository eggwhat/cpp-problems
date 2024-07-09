#include <iostream>

#include "premium_account_manager_factory.h"
#include "standard_account_manager_factory.h"
#include "command_line_interface.h"

int main() {
    auto maintenance = bank::Maintenance();
    auto standardAccountManagerFactory = bank::StandardAccountManagerFactory();
    auto premiumAccountManagerFactory = bank::PremiumAccountManagerFactory();
    int option;
    while(true) {
        std::cout << "Choose an option: " << std::endl;
        std::cout << "1) create new client profile: " << std::endl;
        std::cout << "2) list all clients: " << std::endl;
        std::cout << "3) quit " << std::endl;
        std::cin >> option;

        switch (option) {
            case 1:
                bank_cli::CommandLineInterface::createNewClientProfile(maintenance);
                break;
            case 2:
                bank_cli::CommandLineInterface::chooseClient(maintenance, standardAccountManagerFactory,
                    premiumAccountManagerFactory);
                break;
            case 3:
                return 0;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
}
