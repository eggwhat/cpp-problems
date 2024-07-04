#pragma once

#include "person.h"

namespace bank {
    class BankAccount {
    private:
        Person client;
    public:
        virtual ~BankAccount() = default;
        virtual std::string getAcountDetails() = 0;

        void depositMoney();
        void withdrawMoney();
    };
}
