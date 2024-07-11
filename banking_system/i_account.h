#pragma once

#include <string>

#include "i_funds.h"

namespace bank {
    class IAccount {
    public:
        virtual ~IAccount() = default;

        virtual unsigned int getUserId() const = 0;
        virtual void depositMoney(double money) const = 0;
        virtual void withdrawMoney(double money) const = 0;
        virtual bool isPremium() const = 0;
        virtual std::string getDetails() = 0;
    };
}
