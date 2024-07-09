#pragma once

#include <string>
#include <iostream>

namespace bank {
    class IFunds {
    private:
        double amountOfMoney;
    public:
        explicit IFunds(double const _amountOfMoney): amountOfMoney(_amountOfMoney) {}
        virtual ~IFunds() = default;

        double getAmountOfMoney() const { return amountOfMoney; };
        void depositMoney(double const money) { amountOfMoney += money; }
        void withdrawMoney(double const money) {
            if(0.0 > amountOfMoney - money) {
                std::cout << "You don't have that much money!" << std::endl;
                return;
            }
            amountOfMoney -= money;
        }

        virtual double convertToPLN() = 0;
        virtual double convertToUSD() = 0;
        virtual double convertToEUR() = 0;
        virtual std::string getDetails() = 0;
    };
}
