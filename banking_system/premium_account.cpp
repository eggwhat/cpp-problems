//
// Created by Piotr Padamczyk on 05/07/2024.
//

#include "premium_account.h"

namespace bank {

    std::string PremiumAccount::getDetails() {
        return person->getPersonDetails() + funds->getDetails();
    }


} // bank
