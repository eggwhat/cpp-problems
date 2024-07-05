#pragma once

#include "i_manager.h"

namespace bank {
    class PremiumAccountManager: public IManager {
    public:
        std::string getAccountDetails() override;
        std::unique_ptr<IAccount> createAccount(std::string const& _firstName, std::string const& _middleName,
            std::string const& _lastName) override;
        void depositMoney() override;
        void withdrawMoney() override;
    };
}
