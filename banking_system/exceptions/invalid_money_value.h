#pragma once
#include "exception.h"

namespace exceptions {
    class InvalidMoneyValue: public Exception {
    public:
        explicit InvalidMoneyValue() : Exception("invalid money value.") {}
    };
}
