#pragma once

#include "funds.h"

namespace bank {
    class FundsEUR: public Funds {
    public:
        explicit FundsEUR(double const amountOfMoney): Funds(amountOfMoney) {}

        double convertToPLN() override;
        double convertToUSD() override;
        double convertToEUR() override;
        std::string getDetails() override;
    };
}
