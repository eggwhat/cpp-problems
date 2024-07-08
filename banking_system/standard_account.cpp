#include "standard_account.h"

#include "standard_account_manager.h"

namespace bank {
    std::string StandardAccount::getDetails() {
        return m_person->getPersonDetails() + '\n' + m_funds->getDetails();
    }

    std::unique_ptr<IManager> StandardAccount::getAccountManager() {
        return std::move(std::unique_ptr<StandardAccountManager>());
    }

} // bank
