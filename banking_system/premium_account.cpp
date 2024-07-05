#include "premium_account.h"

#include <numeric>

namespace bank {

    std::string PremiumAccount::getDetails() {
        std::string benefitsToString = std::accumulate( std::begin(benefits), std::end(benefits),
                                "Benefits: ",
                                 [](const std::string& a, const std::string &b ) {
                                    return a.empty() ? b
                                           : a + ',' + b; } );
        return person->getPersonDetails() + '\n' + funds->getDetails() + '\n' + benefitsToString;
    }


} // bank
