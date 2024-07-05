#pragma once

#include <string>
#include <memory>

#include "person.h"
#include "i_funds.h"

namespace bank {
    class IAccount {
    protected:
        std::unique_ptr<Person> const& person;
        std::unique_ptr<IFunds> funds;
    public:
        explicit IAccount(std::unique_ptr<Person> const& _person, std::unique_ptr<IFunds> _funds):
            person(_person), funds(std::move(_funds)) {}
        virtual ~IAccount() = default;

        virtual std::string getDetails() = 0;
    };
}
