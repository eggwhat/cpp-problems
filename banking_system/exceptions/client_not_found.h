#pragma once

#include "exception.h"

namespace exceptions {
    class ClientNotFound: public Exception {
    public:
        explicit ClientNotFound() { m_message += "client with given ID was not found."; }
    };
}
