#include "command_line_interface.h"

#include <iostream>
#include <string>
#include <memory>
#include <utility>

#include "funds_eur.h"
#include "funds_pln.h"
#include "funds_usd.h"
#include "maintenance.h"

namespace bank_cli {
    void CommandLineInterface::init() {
        int option;
        while(true) {
            std::cout << "Choose an option: " << std::endl;
            std::cout << "1) create new client profile: " << std::endl;
            std::cout << "2) list all clients: " << std::endl;
            std::cout << "3) quit " << std::endl;
            std::cin >> option;

            switch (option) {
                case 1:
                    createNewClientProfile();
                break;
                case 2:
                    chooseClient();
                break;
                case 3:
                    return;
                default:
                    std::cout << "Invalid option. Please try again." << std::endl;
            }
        }
    }

    void CommandLineInterface::createNewClientProfile() {
        std::string firstName, middleName, lastName;
        std::cout << "Provide a first name:" << std::endl;
        std::cin >> firstName;
        std::cout << "Provide a middle name:" << std::endl;
        std::cin >> middleName;
        std::cout << "Provide a last name:" << std::endl;
        std::cin >> lastName;
        m_maintenance.addClient(std::make_shared<bank::Person>(firstName, middleName, lastName));
    }

    void CommandLineInterface::depositMoney(std::unique_ptr<bank::IManager> const& accountManager, std::unique_ptr<bank::IAccount> const& account) {
        std::cout << accountManager->getAccountDetails(account);
        std::cout << "Provide amount of money to deposit" << std::endl;
        double moneyToDeposit;
        std::cin >> moneyToDeposit;
        accountManager->depositMoney(account, moneyToDeposit);
        std::cout << accountManager->getAccountDetails(account);
    }

    void CommandLineInterface::withdrawMoney(std::unique_ptr<bank::IManager> const& accountManager, std::unique_ptr<bank::IAccount> const& account) {
        std::cout << accountManager->getAccountDetails(account);
        std::cout << "Provide amount of money to withdraw" << std::endl;
        double moneyToWithdraw;
        std::cin >> moneyToWithdraw;
        accountManager->withdrawMoney(account, moneyToWithdraw);
        std::cout << accountManager->getAccountDetails(account);
    }

    void CommandLineInterface::chooseClient() {
        std::cout << "Choose a client:" << std::endl;
        m_maintenance.listClients();
        unsigned int clientId;
        std::cin >> clientId;
        auto const client = m_maintenance.getClient(clientId);

        int clientOption;
        std::cout << "Choose an option: " << std::endl;
        std::cout << "1) create a new account: " << std::endl;
        std::cout << "2) choose an account: " << std::endl;
        std::cin >> clientOption;
        switch (clientOption) {
            case 1: {
                int isPremiumAccount;
                std::cout << "Premium account (yes=0):" << std::endl;
                std::cin >> isPremiumAccount;
                std::unique_ptr<bank::IFunds> funds;
                std::unique_ptr<bank::IManager> manager;
                if(isPremiumAccount == 0) {
                    manager = premiumAccountManagerFactory.createManager();
                    int fundsOption;
                    std::cout << "Choose a currency: " << std::endl;
                    std::cout << "1) Euro: " << std::endl;
                    std::cout << "2) Polish Zloty: " << std::endl;
                    std::cout << "3) American Dollars: " << std::endl;
                    std::cin >> fundsOption;
                    switch (fundsOption) {
                        case 1:
                            funds = std::make_unique<bank::FundsEUR>(0.0);
                            break;
                        case 2:
                            funds = std::make_unique<bank::FundsPLN>(0.0);
                            break;
                        case 3:
                            funds = std::make_unique<bank::FundsUSD>(0.0);
                            break;
                        default:
                            std::cout << "Invalid option. Please try again." << std::endl;
                            break;
                    }
                }
                else {
                    manager = standardAccountManagerFactory.createManager();
                    funds = std::make_unique<bank::FundsEUR>(0.0);
                }
                m_maintenance.addAccount(manager->createAccount(client, std::move(funds)));
            }
            case 2: {
                std::cout << "Client accounts: " << std::endl;
                auto const accounts = m_maintenance.findClientAccounts(clientId);
                bank::Maintenance::listClientAccounts(accounts);
                std::cout << "Choose account: " << std::endl;
                unsigned int accountIndex;
                std::cin >> accountIndex;
                int accountOption;
                auto const& account = *accounts[accountIndex];
                auto const manager = bank::Maintenance::createAccountManager(account);
                std::cout << "Choose an option: " << std::endl;
                std::cout << "1) show account details: " << std::endl;
                std::cout << "2) deposit money: " << std::endl;
                std::cout << "3) withdraw money: " << std::endl;
                std::cin >> accountOption;
                switch (accountOption) {
                    case 1:
                        std::cout << manager->getAccountDetails(account) << std::endl;
                        break;
                    case 2:
                        depositMoney(manager, account);
                        break;
                    case 3:
                        withdrawMoney(manager, account);
                        break;
                    default:
                        std::cout << "Invalid option. Please try again." << std::endl;
                        break;
                }
                break;
            }
            default:
                break;
        }
    }
} // bank_cli
