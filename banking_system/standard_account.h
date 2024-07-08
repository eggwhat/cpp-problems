#pragma once

#include "i_account.h"

namespace bank {

    class StandardAccount: public IAccount {
    public:
        explicit StandardAccount(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds):
            IAccount(std::move(person), std::move(funds)) {}

        std::string getDetails() override;
        std::unique_ptr<IManager> getAccountManager() override;
    };

} // bank
