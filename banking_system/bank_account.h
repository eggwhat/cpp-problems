#pragma once

#include "person.h"

namespace bank {
    class BankAccount {
    private:
        Person client;
    public:
        enum class AccountType { savingAccount, checkingAccount};

        explicit BankAccount(AccountType type);
        virtual ~BankAccount() = default;

        AccountType accountType;
        virtual std::string getAcountDetails() = 0;
    };
}
