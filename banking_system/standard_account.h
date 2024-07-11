#pragma once

#include "account.h"

#include <memory>
#include <utility>

namespace bank {

    class StandardAccount: public Account {
    public:
        explicit StandardAccount(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds);

        unsigned int getUserId() const override;
        void depositMoney(double money) const override;
        void withdrawMoney(double money) const override;
        bool isPremium() const override;
        std::string getDetails() override;
    };

} // bank
