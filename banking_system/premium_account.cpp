#include "premium_account.h"


namespace bank {

    std::string PremiumAccount::getDetails() {
        return m_person->getPersonDetails() + '\n' + m_funds->getDetails() + '\n' + "Benefits: " +
            std::to_string(benefits.size());
    }


} // bank
