#pragma once

#include <string>

namespace bank {
    class IFunds {
    public:
        virtual ~IFunds() = default;

        virtual double getAmountOfMoney() const = 0;
        virtual void depositMoney(double money) = 0;
        virtual void withdrawMoney(double money) = 0;
        virtual double convertToPLN() = 0;
        virtual double convertToUSD() = 0;
        virtual double convertToEUR() = 0;
        virtual std::string getDetails() = 0;
    };
}
