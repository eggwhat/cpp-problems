#pragma once

#include <set>

#include "i_account.h"

namespace bank {

    class PremiumAccount: public IAccount {
    private:
        enum class Benefits { FreeChecks, DedicatedCustomerService};
        std::set<Benefits> benefits;
    public:
        explicit PremiumAccount(std::shared_ptr<Person> _person, std::unique_ptr<IFunds> _funds):
            IAccount(std::move(_person), std::move(_funds)) {}

        std::string getDetails() override;
    };

} // bank
