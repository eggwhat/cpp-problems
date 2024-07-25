#include <banking/standard_account.h>

#include <banking/standard_account_manager.h>

namespace bank {
    StandardAccount::StandardAccount(unsigned int const clientId, std::unique_ptr<IFunds> funds):
                    Account(clientId, std::move(funds), AccountType::Standard) {}

    std::string StandardAccount::getDetails() {
        return "Type: standard \n" +  m_funds->getDetails();
    }

} // bank
