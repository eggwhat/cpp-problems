#pragma once

#include "person.h"
#include "i_funds.h"

namespace bank {
    class IAccount {
    private:
        bank::Person person;
        bank::IFunds funds;
    public:
    };
}
