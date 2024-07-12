#pragma once

#include "funds.h"

namespace bank {
    class FundsEUR: public Funds {
    public:
        explicit FundsEUR(double const amountOfMoney): Funds(amountOfMoney) {}

        double convertToPLN() const override;
        double convertToUSD() const override;
        double convertToEUR() const override;
        std::string getDetails() override;
    };
}
