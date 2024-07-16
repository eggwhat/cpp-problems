#pragma once

#include "interfaces/i_funds.h"

namespace bank {
    class Funds: public IFunds {
    public:
        explicit Funds(double const amountOfMoney): m_amountOfMoney(amountOfMoney) {}

        double getAmountOfMoney() const final;
        void depositMoney(double money) final;
        void withdrawMoney(double money) final;
    protected:
        double m_amountOfMoney;
    };
}
