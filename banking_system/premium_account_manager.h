#pragma once

#include "i_manager.h"

namespace bank {
    class PremiumAccountManager: public IManager {
    public:
        std::string getAccountDetails(std::unique_ptr<IAccount> account) override;
        std::unique_ptr<IAccount> createAccount(std::string const& firstName, std::string const& middleName,
            std::string const& lastName) override;
        void depositMoney(std::unique_ptr<IAccount> account) override;
        void withdrawMoney(std::unique_ptr<IAccount> account) override;
    };
}
