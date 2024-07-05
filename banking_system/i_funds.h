#pragma once

namespace bank {
    class IFunds {
    private:
        double amountOfMoney;
    public:
        explicit IFunds(double const _amountOfMoney): amountOfMoney(_amountOfMoney) {}
        virtual ~IFunds() = default;

        virtual double convertToPLN() = 0;
        virtual double convertToUSD() = 0;
        virtual double convertToEUR() = 0;

    };
}