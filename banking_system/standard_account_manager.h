#pragma once

#include "i_manager.h"

namespace bank {
    class StandardAccountManager: public IManager {
    public:
        std::string getAccountDetails(std::unique_ptr<IAccount> account) override;
        std::unique_ptr<IAccount> createAccount(std::string const& _firstName, std::string const& _middleName,
            std::string const& _lastName) override;
        void depositMoney(std::unique_ptr<IAccount> account) override;
        void withdrawMoney(std::unique_ptr<IAccount> account) override;
    };
}
