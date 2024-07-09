#pragma once

#include <string>
#include <memory>

#include "i_account.h"

namespace bank {
    class IManager {
    public:
        virtual ~IManager() = default;

        virtual std::string getAccountDetails(std::shared_ptr<IAccount> account) = 0;
        virtual std::unique_ptr<IAccount> createAccount(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds) = 0;
        virtual void depositMoney(std::shared_ptr<IAccount> account, double money) = 0;
        virtual void withdrawMoney(std::shared_ptr<IAccount> account, double money) = 0;

    };
}
