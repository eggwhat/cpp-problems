#pragma once

#include "interfaces/i_account.h"
#include "interfaces/i_funds.h"
#include "person.h"

namespace bank {
    class Account: public IAccount {
    public:
        explicit Account(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds):
            m_person(std::move(person)), m_funds(std::move(funds)) {}

        enum class AccountType { Standard, Premium };
        AccountType accountType;

        unsigned int getUserId() const final;
        void depositMoney(double money) const final;
        void withdrawMoney(double money) const final;
        bool isPremium() const final;
    protected:
        std::shared_ptr<Person> m_person;
        std::unique_ptr<IFunds> m_funds;
    };
}
