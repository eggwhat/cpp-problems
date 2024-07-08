#pragma once

#include "i_account.h"

namespace bank {

    class StandardAccount: public IAccount {
    public:
        explicit StandardAccount(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds);

        std::string getDetails() override;
    };

} // bank
