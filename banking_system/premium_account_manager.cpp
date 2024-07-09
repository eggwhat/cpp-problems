#include "premium_account_manager.h"

#include "funds_eur.h"
#include "premium_account.h"

namespace bank {
    std::unique_ptr<IAccount> PremiumAccountManager::createAccount(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds) {
        return std::make_unique<PremiumAccount>(std::move(person), std::move(funds));
    }

    void PremiumAccountManager::depositMoney(std::shared_ptr<IAccount> account, double const money) {
        account->depositMoney(money);
    }

    void PremiumAccountManager::withdrawMoney(std::shared_ptr<IAccount> account, double const money) {
        account->withdrawMoney(money);
    }

    std::string PremiumAccountManager::getAccountDetails(std::shared_ptr<IAccount> account) {
        return account->getDetails();
    }
} // bank
