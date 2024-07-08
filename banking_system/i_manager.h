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
        virtual std::unique_ptr<IAccount> createAccount(std::string const& firstName, std::string const& middleName,
            std::string const& lastName) = 0;
        virtual void depositMoney(std::unique_ptr<IAccount> account) = 0;
        virtual void withdrawMoney(std::unique_ptr<IAccount> account) = 0;
    };
}
