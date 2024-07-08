#pragma once

#include <string>
#include <memory>
#include <utility>

#include "person.h"
#include "i_funds.h"

namespace bank {
    class IAccount {
    protected:
        std::shared_ptr<Person> person;
        std::unique_ptr<IFunds> funds;
    public:
        explicit IAccount(std::shared_ptr<Person> _person, std::unique_ptr<IFunds> _funds):
            person(std::move(_person)), funds(std::move(_funds)) {}
        virtual ~IAccount() = default;

        virtual std::string getDetails() = 0;
    };
}
