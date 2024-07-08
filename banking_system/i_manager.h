#pragma once

#include <string>
#include <memory>

#include "i_account.h"

namespace bank {
    class IManager {
    private:
    public:
        virtual ~IManager() = default;

        virtual std::string getAccountDetails(std::unique_ptr<IAccount> account) = 0;
        virtual std::unique_ptr<IAccount> createAccount(std::string const& _firstName, std::string const& _middleName,
            std::string const& _lastName) = 0;
        virtual void depositMoney(std::unique_ptr<IAccount> account) = 0;
        virtual void withdrawMoney(std::unique_ptr<IAccount> account) = 0;
    };
}
