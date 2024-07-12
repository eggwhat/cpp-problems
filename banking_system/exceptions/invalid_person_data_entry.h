#pragma once

#include <string>

#include "exception.h"

namespace exceptions {
    class InvalidPersonDataEntry: public Exception {
    public:
        explicit InvalidPersonDataEntry(std::string const& fieldName) {
            m_message += "field cannot be empty '" + fieldName + "'.";
        }
    };
}
