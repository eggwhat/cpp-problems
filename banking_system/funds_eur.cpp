#include "funds_eur.h"

namespace bank {

    double FundsEUR::getAmountOfMoney() const {
        return m_amountOfMoney;
    }

    void FundsEUR::depositMoney(double const money) {
        m_amountOfMoney += money;
    }

    void FundsEUR::withdrawMoney(double const money) {
        if(0.0 > m_amountOfMoney - money) {
            std::cout << "You don't have that much money!" << std::endl;
            return;
        }
        m_amountOfMoney -= money;
    }

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
        return "Funds: " + std::to_string(getAmountOfMoney()) + " Euro" + '\n'
            + "equals: " + std::to_string(convertToPLN()) + " in Polish Zloty" + '\n'
            + "equals: " + std::to_string(convertToUSD()) + " in American Dollars" + '\n';
    }

}
