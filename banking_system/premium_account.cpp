#include "premium_account.h"

#include "premium_account_manager.h"


namespace bank {
    PremiumAccount::PremiumAccount(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds):
            IAccount(std::move(person), std::move(funds)) {
        accountType = AccountType::Premium;
        benefits = std::set<Benefits> { Benefits::FreeChecks, Benefits::DedicatedCustomerService };
    }

    std::string PremiumAccount::getDetails() {
        return m_person->getPersonDetails() + '\n' + m_funds->getDetails() + "Benefits: " +
            std::to_string(benefits.size()) + '\n';
    }

} // bank
