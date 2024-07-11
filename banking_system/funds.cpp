#include "funds.h"

namespace bank {

    double Funds::getAmountOfMoney() const {
        return m_amountOfMoney;
    }

    void Funds::depositMoney(double const money) {
        m_amountOfMoney += money;
    }

    void Funds::withdrawMoney(double const money) {
        if(0.0 > m_amountOfMoney - money) {
            std::cout << "You don't have that much money!" << std::endl;
            return;
        }
        m_amountOfMoney -= money;
    }
}