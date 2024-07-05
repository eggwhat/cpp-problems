#pragma once

#include "i_funds.h"

namespace bank {
    class FundsUSD: public IFunds {

    public:
        double convertToPLN() override;
        double convertToUSD() override;
        double convertToEUR() override;
        std::string getDetails() override;

    };
}
