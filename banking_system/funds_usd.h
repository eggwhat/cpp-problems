#pragma once

#include "i_funds.h"

namespace bank {
    class FundsUSD: public IFunds {

    public:
        explicit FundsUSD(double const _amountOfMoney): IFunds(_amountOfMoney) {}

        double convertToPLN() override;
        double convertToUSD() override;
        double convertToEUR() override;
        std::string getDetails() override;

    };
}
