#include "standard_account.h"

#include "standard_account_manager.h"

namespace bank {
    StandardAccount::StandardAccount(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds):
                    Account(std::move(person), std::move(funds)) {
        accountType = AccountType::Standard;
    }

    unsigned int StandardAccount::getUserId() const {
        return m_person->id;
    }

    void StandardAccount::depositMoney(double const money) const {
        m_funds->depositMoney(money);
    }

    void StandardAccount::withdrawMoney(double const money) const {
        m_funds->withdrawMoney(money);
    }

    bool StandardAccount::isPremium() const {
        return accountType == Account::AccountType::Premium;
    }

    std::string StandardAccount::getDetails() {
        return m_person->getPersonDetails() + '\n' + "Type: standard" + '\n' +  m_funds->getDetails();
    }

} // bank
