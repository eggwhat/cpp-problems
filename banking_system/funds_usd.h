#pragma once

#include "funds.h"

namespace bank {
    class FundsUSD: public Funds {
    public:
        explicit FundsUSD(double const amountOfMoney): Funds(amountOfMoney) {}

        double convertToPLN() override;
        double convertToUSD() override;
        double convertToEUR() override;
        std::string getDetails() override;
    };
}
