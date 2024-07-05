#pragma once

#include <string>
#include <memory>

#include "i_account.h"

namespace bank {
    class IManager {
    private:
    public:
        virtual ~IManager() = 0;

        virtual std::string getAccountDetails() = 0;
        virtual std::unique_ptr<IAccount> createAccount() = 0;
        virtual void depositMoney() = 0;
        virtual void withdrawMoney() = 0;
    };
}
