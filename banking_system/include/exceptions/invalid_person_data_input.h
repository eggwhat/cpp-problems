#pragma once

#include <string>

#include "exception.h"

namespace exceptions {
    class InvalidPersonDataInput: public Exception {
    public:
        explicit InvalidPersonDataInput(std::string const& fieldName)
            : Exception("field cannot be empty or contain non-alphabetic characters '" + fieldName + "'.") {}
    };
}
