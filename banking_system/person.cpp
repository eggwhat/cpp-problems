#include "person.h"

namespace bank {
    std::string Person::getPersonDetails() {
        return name + " " + surname;
    }

} // bank