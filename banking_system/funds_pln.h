#pragma once

#include "funds.h"

namespace bank {
    class FundsPLN: public Funds {
    public:
        explicit FundsPLN(double const amountOfMoney): Funds(amountOfMoney) {}

        double convertToPLN() override;
        double convertToUSD() override;
        double convertToEUR() override;
        std::string getDetails() override;
    };
}
