#pragma once

#include <set>

#include "i_account.h"

namespace bank {

    class PremiumAccount: public IAccount {
    private:
        enum class Benefits { FreeChecks, DedicatedCustomerService};
        std::set<Benefits> benefits;
    public:
        explicit PremiumAccount(std::unique_ptr<Person> const& _person, std::shared_ptr<IFunds> _funds):
            IAccount(_person, std::move(_funds)) {}

        std::string getDetails() override;
    };

} // bank
