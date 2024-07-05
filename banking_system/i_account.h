#pragma once

#include <string>

#include "person.h"
#include "i_funds.h"

namespace bank {
    class IAccount {
    private:
        bank::Person person;
        bank::IFunds funds;
    public:
        virtual std::string getDetail() = 0;
    };
}
