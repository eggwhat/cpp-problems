#pragma once

#include "account.h"

#include <set>
#include <memory>
#include <utility>

namespace bank {

    class PremiumAccount: public Account {
    public:
        explicit PremiumAccount(Person person, std::unique_ptr<IFunds> funds);

        std::string getDetails() override;
    private:
        enum class Benefits { FreeChecks, DedicatedCustomerService};
        std::set<Benefits> benefits;
    };

} // bank
