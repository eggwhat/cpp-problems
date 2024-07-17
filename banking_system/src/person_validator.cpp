#include "validators/person_validator.h"

namespace validators {

    PersonValidator::PersonValidator() : m_namePattern("^[\\w'\\-,.][^0-9_!¡?÷?¿/\\+=@#$%ˆ&*(){}|~<>;:[\\]]{2,}$") {}

    bool PersonValidator::validateName(std::string const& name) const {
        return regex_match(name, m_namePattern);
    }
}
