#include "standard_account.h"

namespace bank {
    std::string StandardAccount::getDetails() {
        return person->getPersonDetails() + '\n' + funds->getDetails();
    }
} // bank
