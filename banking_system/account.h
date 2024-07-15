#pragma once

#include "interfaces/i_account.h"
#include "interfaces/i_funds.h"
#include "person.h"

namespace bank {
    class Account: public IAccount {
    public:
        enum class AccountType { Standard, Premium };

        explicit Account(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds, AccountType accountType);

        unsigned int getUserId() const final;
        void depositMoney(double money) const final;
        void withdrawMoney(double money) const final;
        bool isPremium() const final;

        AccountType m_accountType;
    protected:
        std::shared_ptr<Person> m_person;
        std::unique_ptr<IFunds> m_funds;
    };
}
