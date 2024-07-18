#include <banking/funds.h>

#include "exceptions/not_enough_funds.h"

namespace bank {

    double Funds::getAmountOfMoney() const {
        return m_amountOfMoney;
    }

    void Funds::depositMoney(double const money) {
        m_amountOfMoney += money;
    }

    void Funds::withdrawMoney(double const money) {
        if(0.0 > m_amountOfMoney - money) {
            throw exceptions::NotEnoughFunds();
        }
        m_amountOfMoney -= money;
    }
}
