#pragma once

#include "i_funds.h"

namespace bank {
    class FundsEUR: public IFunds {

    public:
        double convertToPLN() override;
        double convertToUSD() override;
        double convertToEUR() override;
        std::string getDetails() override;

    };
}
