#pragma once

#include <string>
#include <memory>
#include <utility>

#include "person.h"
#include "i_funds.h"
#include "i_manager.h"

namespace bank {
    class IAccount {
    protected:
        std::shared_ptr<Person> m_person;
        std::unique_ptr<IFunds> m_funds;
    public:
        explicit IAccount(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds):
            m_person(std::move(person)), m_funds(std::move(funds)) {}
        virtual ~IAccount() = default;

        unsigned int getUserId() const { return m_person->id; }
        void depositMoney(double const money) const { m_funds->depositMoney(money); }
        void withdrawMoney(double const money) const { m_funds->withdrawMoney(money); }

        virtual std::string getDetails() = 0;
        virtual std::unique_ptr<IManager> getAccountManager() = 0;
    };
}
