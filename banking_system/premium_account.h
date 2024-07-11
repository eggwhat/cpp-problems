#pragma once

#include "account.h"

#include <set>
#include <memory>
#include <utility>

namespace bank {

    class PremiumAccount: public Account {
    public:
        explicit PremiumAccount(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds);

        unsigned int getUserId() const override;
        void depositMoney(double money) const override;
        void withdrawMoney(double money) const override;
        bool isPremium() const override;
        std::string getDetails() override;
    private:
        enum class Benefits { FreeChecks, DedicatedCustomerService};
        std::set<Benefits> benefits;
    };

} // bank
