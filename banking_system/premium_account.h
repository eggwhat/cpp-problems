#pragma once
#include "i_account.h"

namespace bank {

    class PremiumAccount: public IAccount {
    private:
    public:
        explicit PremiumAccount(std::unique_ptr<Person> const& _person, std::unique_ptr<IFunds> _funds):
            IAccount(_person, std::move(_funds)) {}

        std::string getDetails() override;
    };

} // bank
