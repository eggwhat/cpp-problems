#include "premium_account_manager.h"

#include "funds_eur.h"
#include "premium_account.h"

namespace bank {
    std::unique_ptr<IAccount> PremiumAccountManager::createAccount(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds) {
        return std::make_unique<PremiumAccount>(std::move(person), std::move(funds));
    }

    void PremiumAccountManager::depositMoney(std::unique_ptr<IAccount> const& account, double const money) {
        account->depositMoney(money);
    }

    void PremiumAccountManager::withdrawMoney(std::unique_ptr<IAccount> const& account, double const money) {
        account->withdrawMoney(money);
    }

    std::string PremiumAccountManager::getAccountDetails(std::unique_ptr<IAccount> const& account) {
        return account->getDetails();
    }
} // bank
