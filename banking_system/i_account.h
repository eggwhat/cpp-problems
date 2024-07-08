#pragma once

#include <string>
#include <memory>
#include <utility>

#include "person.h"
#include "i_funds.h"

namespace bank {
    class IAccount {
    protected:
        std::shared_ptr<Person> m_person;
        std::unique_ptr<IFunds> m_funds;
    public:
        explicit IAccount(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds):
            m_person(std::move(person)), m_funds(std::move(funds)) {}
        virtual ~IAccount() = default;

        void depositMoney(double const money) { m_funds->depositMoney(money); }
        void withdrawMoney(double const money) { m_funds->withdrawMoney(money); }

        virtual std::string getDetails() = 0;
    };
}
