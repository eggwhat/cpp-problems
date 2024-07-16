#pragma once

#include "funds.h"

namespace bank {
    class FundsUSD: public Funds {
    public:
        explicit FundsUSD(double const amountOfMoney): Funds(amountOfMoney) {}

        double convertToPLN() const override;
        double convertToUSD() const override;
        double convertToEUR() const override;
        std::string getDetails() override;
    };
}
