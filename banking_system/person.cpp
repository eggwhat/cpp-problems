#include "person.h"

namespace bank {
    std::string Person::getPersonDetails() {
        return !middleName.empty() ? firstName + " " + middleName + " " + lastName : firstName + " " + lastName;
    }

} // bank
