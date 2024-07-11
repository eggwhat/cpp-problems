#pragma once

#include "funds.h"

namespace bank {
    class FundsUSD: public Funds {
    public:
        explicit FundsUSD(double const amountOfMoney): Funds(amountOfMoney) {}

        double getAmountOfMoney() const override;
        void depositMoney(double money) override;
        void withdrawMoney(double money) override;
        double convertToPLN() override;
        double convertToUSD() override;
        double convertToEUR() override;
        std::string getDetails() override;
    };
}
