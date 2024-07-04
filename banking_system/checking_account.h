#pragma once
#include "bank_account.h"

namespace bank {
    class CheckingAccount: public BankAccount {
    public:
        std::string getAcountDetails() override;
    };
}
