#pragma once

#include <string>

namespace bank {
    class IFunds {
    private:
        double amountOfMoney;
    public:
        explicit IFunds(double const _amountOfMoney): amountOfMoney(_amountOfMoney) {}
        virtual ~IFunds() = default;

        double getAmountOfMoney() const { return amountOfMoney; };

        virtual double convertToPLN() = 0;
        virtual double convertToUSD() = 0;
        virtual double convertToEUR() = 0;
        virtual std::string getDetails() = 0;
    };
}
