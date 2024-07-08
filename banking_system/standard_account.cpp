#include "standard_account.h"

namespace bank {
    std::string StandardAccount::getDetails() {
        return m_person->getPersonDetails() + '\n' + m_funds->getDetails();
    }
} // bank
