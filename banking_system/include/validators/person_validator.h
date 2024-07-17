#pragma once

#include <string>
#include <boost/regex.hpp>

#include "validator.h"

namespace validators {
    class PersonValidator: public Validator {
    public:
        PersonValidator();

        bool validateName(std::string const& name) const;
    private:
        boost::regex const m_namePattern;
    };
}
