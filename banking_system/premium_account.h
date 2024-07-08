#pragma once

#include <set>

#include "i_account.h"

namespace bank {

    class PremiumAccount: public IAccount {
    private:
        enum class Benefits { FreeChecks, DedicatedCustomerService};
        std::set<Benefits> benefits;
    public:
        explicit PremiumAccount(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds):
            IAccount(std::move(person), std::move(funds)) {}

        std::string getDetails() override;
    };

} // bank
