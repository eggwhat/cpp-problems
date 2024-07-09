#pragma once

#include "i_manager.h"

namespace bank {
    class StandardAccountManager: public IManager {
    public:
        std::string getAccountDetails(std::shared_ptr<IAccount> account) override;
        std::unique_ptr<IAccount> createAccount(std::shared_ptr<Person> person) override;
        void depositMoney(std::unique_ptr<IAccount> account, double money) override;
        void withdrawMoney(std::unique_ptr<IAccount> account, double money) override;
    };
}
