#pragma once

#include <string>

#include "maintenance.h"
#include "premium_account_manager.h"
#include "premium_account_manager_factory.h"
#include "standard_account_manager_factory.h"

namespace bank_cli {
    class CommandLineInterface {
    public:
        explicit CommandLineInterface(bank::Maintenance& maintenance): m_maintenance(maintenance),
            standardAccountManagerFactory(bank::StandardAccountManagerFactory()),
            premiumAccountManagerFactory(bank::PremiumAccountManagerFactory()) {}

        void init();
        void createNewClientProfile();
        void depositMoney(std::unique_ptr<bank::IManager> const &accountManager,
                   std::unique_ptr<bank::IAccount> const& account);
        void withdrawMoney(std::unique_ptr<bank::IManager> const &accountManager,
                    std::unique_ptr<bank::IAccount> const& account);
        void chooseClient();
    private:
        bank::Maintenance& m_maintenance;
        bank::StandardAccountManagerFactory standardAccountManagerFactory;
        bank::PremiumAccountManagerFactory premiumAccountManagerFactory;
        int chooseOption(int lowestOptionNumber, int numberOfOptions);
        std::string provideAlphanumericString(std::string const& fieldName);
        double provideAmountOfMoney();
    };
}
