#pragma once

#include "account.h"

#include <memory>
#include <utility>

namespace bank {

    class StandardAccount: public Account {
    public:
        explicit StandardAccount(Person person, std::unique_ptr<IFunds> funds);

        std::string getDetails() override;
    };

} // bank
