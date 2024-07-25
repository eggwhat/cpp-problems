#pragma once

#include "interfaces/i_manager.h"

namespace bank {
    class PremiumAccountManager: public IManager {
    public:
        std::string getAccountDetails(std::unique_ptr<IAccount> const& account) override;
        std::unique_ptr<IAccount> createAccount(std::unique_ptr<Person> const& person, std::unique_ptr<IFunds> funds) override;
        void depositMoney(std::unique_ptr<IAccount> const& account, double money) override;
        void withdrawMoney(std::unique_ptr<IAccount> const& account, double money) override;
    };
}
