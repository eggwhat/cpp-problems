#include "funds_usd.h"

namespace bank {

    double FundsUSD::getAmountOfMoney() const {
        return m_amountOfMoney;
    }

    void FundsUSD::depositMoney(double const money) {
        m_amountOfMoney += money;
    }

    void FundsUSD::withdrawMoney(double const money) {
        if(0.0 > m_amountOfMoney - money) {
            std::cout << "You don't have that much money!" << std::endl;
            return;
        }
        m_amountOfMoney -= money;
    }

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
        return "Funds: " + std::to_string(getAmountOfMoney()) + " American Dollars" + '\n'
            + "equals: " + std::to_string(convertToPLN()) + " in Polish Zloty" + '\n'
            + "equals: " + std::to_string(convertToEUR()) + " in Euro" + '\n';
    }

}
