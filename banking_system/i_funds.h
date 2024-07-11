#pragma once

#include <string>
#include <iostream>

namespace bank {
    class IFunds {
    public:
        virtual ~IFunds() = default;

        virtual double getAmountOfMoney() const;
        virtual void depositMoney(double money);
        virtual void withdrawMoney(double money);
        virtual double convertToPLN() = 0;
        virtual double convertToUSD() = 0;
        virtual double convertToEUR() = 0;
        virtual std::string getDetails() = 0;
    };
}
