#pragma once
#include "exception.h"

namespace exceptions {
    class InvalidMoneyValue: public Exception {
    public:
        explicit InvalidMoneyValue() {
            m_message += "invalid money value.";
        }
    };
}
