#include "command_line_interface.h"

#include <iostream>
#include <string>
#include <memory>
#include <utility>

#include "funds_eur.h"
#include "funds_pln.h"
#include "funds_usd.h"
#include "maintenance.h"
#include "exceptions/exception.h"
#include "exceptions/invalid_money_value.h"

namespace bank_cli {
    void CommandLineInterface::init() {
        while(true) {
            try {
                std::cout << "Choose an option: " << std::endl;
                std::cout << "1) create new client profile: " << std::endl;
                std::cout << "2) list all clients: " << std::endl;
                std::cout << "3) quit " << std::endl;

                switch (chooseOption(3)) {
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
            catch (exceptions::Exception& exception) {
                std::cerr << exception.what() << std::endl << std::flush;
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
        double moneyToDeposit = provideAmountOfMoney();
        accountManager->depositMoney(account, moneyToDeposit);
        std::cout << accountManager->getAccountDetails(account);
    }

    void CommandLineInterface::withdrawMoney(std::unique_ptr<bank::IManager> const& accountManager, std::unique_ptr<bank::IAccount> const& account) {
        std::cout << accountManager->getAccountDetails(account);
        std::cout << "Provide amount of money to withdraw" << std::endl;
        double moneyToWithdraw = provideAmountOfMoney();
        accountManager->withdrawMoney(account, moneyToWithdraw);
        std::cout << accountManager->getAccountDetails(account);
    }

    void CommandLineInterface::chooseClient() {
        std::cout << "Choose a client:" << std::endl;
        m_maintenance.listClients();
        unsigned int clientId;
        std::cin >> clientId;
        auto const client = m_maintenance.getClient(clientId);

        std::cout << "Choose an option: " << std::endl;
        std::cout << "1) create a new account: " << std::endl;
        std::cout << "2) choose an account: " << std::endl;
        switch (chooseOption(2)) {
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
                int accountIndex = chooseOption(accounts.size());
                auto const& account = *accounts[accountIndex];
                auto const manager = bank::Maintenance::createAccountManager(account);
                std::cout << "Choose an option: " << std::endl;
                std::cout << "1) show account details: " << std::endl;
                std::cout << "2) deposit money: " << std::endl;
                std::cout << "3) withdraw money: " << std::endl;
                switch (chooseOption(3)) {
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

    int CommandLineInterface::chooseOption(int numberOfOptions) {
        int option;
        while (true) {
            std::cin >> option;
            if (!std::cin.fail() && option >= 1 && option <= numberOfOptions)
                break;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Provide valid option!" << std::endl;
        }
        return option;
    }

    double CommandLineInterface::provideAmountOfMoney() {
        double money;
        std::cin >> money;
        if(std::cin.fail())
            throw exceptions::InvalidMoneyValue();
        return money;
    }

} // bank_cli
