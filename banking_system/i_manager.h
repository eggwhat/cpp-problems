#pragma once

#include <string>
#include <memory>

#include "i_account.h"

namespace bank {
    class IManager {
    public:
        virtual ~IManager() = default;

        virtual std::string getAccountDetails(std::unique_ptr<IAccount> const& account) = 0;
        virtual std::unique_ptr<IAccount> createAccount(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds) = 0;
        virtual void depositMoney(std::unique_ptr<IAccount> const& account, double money) = 0;
        virtual void withdrawMoney(std::unique_ptr<IAccount> const& account, double money) = 0;

    };
}
