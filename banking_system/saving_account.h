#pragma once
#include "bank_account.h"

namespace bank {

    class SavingAccount: public BankAccount {
    private:
        double interestRate;
    public:
        explicit SavingAccount(double interestRate);
        std::string getAcountDetails() override;
    };
}
