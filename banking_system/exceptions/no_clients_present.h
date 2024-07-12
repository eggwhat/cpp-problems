#pragma once

#include "exception.h"

namespace exceptions {
    class NoClientsPresent: public Exception {
    public:
        explicit NoClientsPresent() { m_message += "no clients present in database."; }
    };
}
