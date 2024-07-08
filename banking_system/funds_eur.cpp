#include "funds_eur.h"

namespace bank {

    double FundsEUR::convertToPLN() {
        // http request to get current exchange rate
        double constexpr eurToPlnRate = 4.28;
        return getAmountOfMoney() * eurToPlnRate;
    }

    double FundsEUR::convertToUSD() {
        // http request to get current exchange rate
        double constexpr eurToUsdRate = 1.08;
        return getAmountOfMoney() * eurToUsdRate;
    }

    double FundsEUR::convertToEUR() {
        return getAmountOfMoney();
    }

    std::string FundsEUR::getDetails() {
        return "Funds: " + std::to_string(getAmountOfMoney()) + " Euro"
            + "equals: " + std::to_string(convertToPLN()) + " in Polish Zloty" + '\n'
            + "equals: " + std::to_string(convertToUSD()) + "in American Dollars" + '\n';
    }

}
