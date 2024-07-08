#include "premium_account.h"


namespace bank {

    std::string PremiumAccount::getDetails() {
        return person->getPersonDetails() + '\n' + funds->getDetails() + '\n' + "Benefits: " +
            std::to_string(benefits.size());
    }


} // bank
