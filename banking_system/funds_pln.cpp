#include "funds_pln.h"

namespace bank {

    double FundsPLN::getAmountOfMoney() const {
        return m_amountOfMoney;
    }

    void FundsPLN::depositMoney(double const money) {
        m_amountOfMoney += money;
    }

    void FundsPLN::withdrawMoney(double const money) {
        if(0.0 > m_amountOfMoney - money) {
            std::cout << "You don't have that much money!" << std::endl;
            return;
        }
        m_amountOfMoney -= money;
    }

    double FundsPLN::convertToPLN() {
        return getAmountOfMoney();
    }

    double FundsPLN::convertToUSD() {
        // http request to get current exchange rate
        double constexpr eurToUsdRate = 0.25;
        return getAmountOfMoney() * eurToUsdRate;
    }

    double FundsPLN::convertToEUR() {
        // http request to get current exchange rate
        double constexpr plnToEurRate = 0.23;
        return getAmountOfMoney() * plnToEurRate;
    }

    std::string FundsPLN::getDetails() {
        return "Funds: " + std::to_string(getAmountOfMoney()) + " Polish Zloty" + '\n'
            + "equals: " + std::to_string(convertToUSD()) + " in American Dollars" + '\n'
            + "equals: " + std::to_string(convertToEUR()) + " in Euro" + '\n';
    }

}
