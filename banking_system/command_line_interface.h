#pragma once

#include "maintenance.h"
#include "premium_account_manager.h"
#include "premium_account_manager_factory.h"
#include "standard_account_manager_factory.h"
#include "command_line_interface.h"

namespace bank_cli {
    class CommandLineInterface {
    public:
        CommandLineInterface(): standardAccountManagerFactory(bank::StandardAccountManagerFactory()),
            premiumAccountManagerFactory(bank::PremiumAccountManagerFactory()) {}

        void init(bank::Maintenance& maintenance);

        void createNewClientProfile(bank::Maintenance& maintenance);

        void depositMoney(std::unique_ptr<bank::IManager> const &accountManager,
                   std::unique_ptr<bank::IAccount> const& account);

        void withdrawMoney(std::unique_ptr<bank::IManager> const &accountManager,
                    std::unique_ptr<bank::IAccount> const& account);

        void chooseClient(bank::Maintenance& maintenance);
    private:
        bank::StandardAccountManagerFactory standardAccountManagerFactory;
        bank::PremiumAccountManagerFactory premiumAccountManagerFactory;
    };
}
