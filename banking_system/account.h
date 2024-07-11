#pragma once

#include "i_account.h"
#include "person.h"

namespace bank {
    class Account: public IAccount {
    public:
        explicit Account(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds):
            m_person(std::move(person)), m_funds(std::move(funds)) {}

        enum class AccountType { Standard, Premium };
        AccountType accountType;
    protected:
        std::shared_ptr<Person> m_person;
        std::unique_ptr<IFunds> m_funds;
    };
}
