#pragma once

#include "i_funds.h"

namespace bank {
    class Funds: public IFunds {
    public:
        explicit Funds(double const amountOfMoney): m_amountOfMoney(amountOfMoney) {}
    protected:
        double m_amountOfMoney;
    };
}
