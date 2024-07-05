#pragma once
#include "i_account.h"

namespace bank {

    class StandardAccount: public IAccount {
        explicit StandardAccount(std::unique_ptr<Person>& _person, std::unique_ptr<IFunds> _funds):
            IAccount(_person, std::move(_funds)) {}

        std::string getDetails() override;
    };

} // bank
