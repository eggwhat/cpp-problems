#pragma once

#include "i_account.h"

namespace bank {

    class StandardAccount: public IAccount {
    public:
        explicit StandardAccount(std::shared_ptr<Person> _person, std::unique_ptr<IFunds> _funds):
            IAccount(std::move(_person), std::move(_funds)) {}

        std::string getDetails() override;
    };

} // bank
