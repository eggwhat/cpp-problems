#include <banking/standard_account.h>

#include <banking/standard_account_manager.h>

namespace bank {
    StandardAccount::StandardAccount(Person person, std::unique_ptr<IFunds> funds):
                    Account(std::move(person), std::move(funds), AccountType::Standard) {}

    std::string StandardAccount::getDetails() {
        return m_person.getPersonDetails() + '\n' + "Type: standard" + '\n' +  m_funds->getDetails();
    }

} // bank
