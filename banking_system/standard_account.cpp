#include "standard_account.h"

#include "standard_account_manager.h"

namespace bank {
    StandardAccount::StandardAccount(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds):
                    IAccount(std::move(person), std::move(funds)) {
        accountType = AccountType::Standard;
    }

    std::string StandardAccount::getDetails() {
        return m_person->getPersonDetails() + '\n' + "Type: standard" + '\n' +  m_funds->getDetails();
    }

} // bank
