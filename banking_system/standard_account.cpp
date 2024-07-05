#include "standard_account.h"

namespace bank {
    std::string StandardAccount::getDetails() {
        return person->getPersonDetails() + funds->getDetails();
    }
} // bank
