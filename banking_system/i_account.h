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

        virtual std::string getDetails() = 0;
    };
}
