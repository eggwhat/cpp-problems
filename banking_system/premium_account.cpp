#include "premium_account.h"

#include "premium_account_manager.h"


namespace bank {

    std::string PremiumAccount::getDetails() {
        return m_person->getPersonDetails() + '\n' + m_funds->getDetails() + '\n' + "Benefits: " +
            std::to_string(benefits.size());
    }

    std::unique_ptr<IManager> PremiumAccount::getAccountManager() {
        return std::unique_ptr<PremiumAccountManager>();
    }

} // bank
