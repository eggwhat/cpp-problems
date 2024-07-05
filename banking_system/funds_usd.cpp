#include "funds_usd.h"

namespace bank {

    double FundsUSD::convertToPLN() {
        // http request to get current exchange rate
        double constexpr plnToEurRate = 3.95;
        return getAmountOfMoney() * plnToEurRate;
    }

    double FundsUSD::convertToUSD() {
        return getAmountOfMoney();
    }

    double FundsUSD::convertToEUR() {
        // http request to get current exchange rate
        double constexpr plnToEurRate = 0.92;
        return getAmountOfMoney() * plnToEurRate;
    }

    std::string FundsUSD::getDetails() {
        return "Funds: " + std::to_string(getAmountOfMoney()) + "American Dollars";
    }

}
