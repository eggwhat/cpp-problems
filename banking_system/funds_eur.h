#pragma once

#include "funds.h"

namespace bank {
    class FundsEUR: public Funds {

    public:
        explicit FundsEUR(double const amountOfMoney): Funds(amountOfMoney) {}

        double getAmountOfMoney() const override;
        void depositMoney(double money) override;
        void withdrawMoney(double money) override;
        double convertToPLN() override;
        double convertToUSD() override;
        double convertToEUR() override;
        std::string getDetails() override;

    };
}
