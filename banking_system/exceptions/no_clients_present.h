#pragma once

#include "exception.h"

namespace exceptions {
    class NoClientsPresent: public Exception {
    public:
        explicit NoClientsPresent() : Exception("no clients present in database.") {}
    };
}
