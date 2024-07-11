#include "account.h"

namespace bank {

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
        return accountType == Account::AccountType::Premium;
    }
}
