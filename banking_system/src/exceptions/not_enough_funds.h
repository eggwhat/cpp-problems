#pragma once

#include "exception.h"

namespace exceptions {
    class NotEnoughFunds: public Exception {
    public:
        explicit NotEnoughFunds() : Exception("not enough funds to withdraw.") {}
    };
}
