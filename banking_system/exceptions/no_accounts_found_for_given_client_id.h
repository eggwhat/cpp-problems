#pragma once

#include "exception.h"

namespace exceptions {
    class NoAccountFoundForGivenClientId: public Exception {
    public:
        explicit NoAccountFoundForGivenClientId() : Exception("no accounts found for given client ID.") {}
    };
}
