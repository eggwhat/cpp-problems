#include "account.h"

namespace bank {

    Account::Account(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds, AccountType accountType) :
            m_accountType(accountType), m_person(std::move(person)), m_funds(std::move(funds)) {}

    unsigned int Account::getUserId() const {
        return m_person->id;
    }

    void Account::depositMoney(double const money) const {
        m_funds->depositMoney(money);
    }

    void Account::withdrawMoney(double const money) const {
        m_funds->withdrawMoney(money);
    }

    bool Account::isPremium() const {
        return m_accountType == AccountType::Premium;
    }
}
