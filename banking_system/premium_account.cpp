#include "premium_account.h"

#include "premium_account_manager.h"


namespace bank {

    PremiumAccount::PremiumAccount(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds):
            Account(std::move(person), std::move(funds)) {
        accountType = AccountType::Premium;
        benefits = std::set<Benefits> { Benefits::FreeChecks, Benefits::DedicatedCustomerService };
    }

    unsigned int PremiumAccount::getUserId() const {
        return m_person->id;
    }

    void PremiumAccount::depositMoney(double const money) const {
        m_funds->depositMoney(money);
    }

    void PremiumAccount::withdrawMoney(double const money) const {
        m_funds->withdrawMoney(money);
    }

    bool PremiumAccount::isPremium() const {
        return accountType == Account::AccountType::Premium;
    }

    std::string PremiumAccount::getDetails() {
        return m_person->getPersonDetails() + '\n' + "Type: premium" + '\n' + m_funds->getDetails() + "Benefits: " +
            std::to_string(benefits.size()) + '\n';
    }
} // bank
