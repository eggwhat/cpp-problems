#pragma once

#include "maintenance.h"
#include "premium_account_manager.h"
#include "premium_account_manager_factory.h"
#include "standard_account_manager_factory.h"
#include "command_line_interface.h"

namespace bank_cli {
    class CommandLineInterface {
    public:
        static void createNewClientProfile(bank::Maintenance& maintenance);

        static void depositMoney(std::unique_ptr<bank::IManager> const &accountManager,
                          std::unique_ptr<bank::IAccount> const& account);

        static void withdrawMoney(std::unique_ptr<bank::IManager> const &accountManager,
                           std::unique_ptr<bank::IAccount> const& account);

        static void chooseClient(bank::Maintenance& maintenance,
                          bank::StandardAccountManagerFactory& standardAccountManagerFactory,
                          bank::PremiumAccountManagerFactory& premiumAccountManagerFactory);
    };
}
