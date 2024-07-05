#pragma once

#include <string>

#include "person.h"
#include "i_funds.h"

namespace bank {
    class IAccount {
    private:
        std::unique_ptr<Person>& person;
        std::unique_ptr<IFunds> funds;
    public:
        explicit IAccount(std::unique_ptr<Person> & _person, std::unique_ptr<IFunds> _funds):
            person(_person), funds(std::move(_funds)) {}
        virtual ~IAccount() = default;

        virtual std::string getDetail() = 0;
    };
}
