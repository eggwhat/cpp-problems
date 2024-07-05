#pragma once

#include <string>

#include "person.h"
#include "i_funds.h"

namespace bank {
    class IAccount {
    private:
        std::unique_ptr<Person> person;
        IFunds funds;
    public:
        explicit IAccount(std::unique_ptr<Person> const& _person): person(_person) {}
        virtual ~IAccount() = default;

        virtual std::string getDetail() = 0;
    };
}
