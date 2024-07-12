#pragma once

#include "exception.h"

namespace exceptions {
    class NotEnoughFunds: public Exception {
    public:
        explicit NotEnoughFunds() { m_message += "not enough funds to withdraw."; }
    };
}
