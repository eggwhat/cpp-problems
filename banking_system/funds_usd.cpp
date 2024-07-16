#include "funds_usd.h"

namespace bank {

    double FundsUSD::convertToPLN() const {
        // http request to get current exchange rate
        double constexpr plnToEurRate = 3.95;
        return getAmountOfMoney() * plnToEurRate;
    }

    double FundsUSD::convertToUSD() const {
        return getAmountOfMoney();
    }

    double FundsUSD::convertToEUR() const {
        // http request to get current exchange rate
        double constexpr plnToEurRate = 0.92;
        return getAmountOfMoney() * plnToEurRate;
    }

    std::string FundsUSD::getDetails() {
        return "Funds: " + std::to_string(getAmountOfMoney()) + " American Dollars" + '\n'
            + "equals: " + std::to_string(convertToPLN()) + " in Polish Zloty" + '\n'
            + "equals: " + std::to_string(convertToEUR()) + " in Euro" + '\n';
    }

}
