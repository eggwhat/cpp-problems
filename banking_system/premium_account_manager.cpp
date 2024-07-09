#include "premium_account_manager.h"

#include "funds_eur.h"
#include "premium_account.h"

namespace bank {
    std::unique_ptr<IAccount> PremiumAccountManager::createAccount(std::shared_ptr<Person> person) {
        std::unique_ptr<IFunds> funds = std::make_unique<FundsEUR>(0.0);
        return std::make_unique<PremiumAccount>(std::move(person), std::move(funds));
    }

    void PremiumAccountManager::depositMoney(std::unique_ptr<IAccount> account, double const money) {
        account->depositMoney(money);
    }

    void PremiumAccountManager::withdrawMoney(std::unique_ptr<IAccount> account, double const money) {
        account->withdrawMoney(money);
    }

    std::string PremiumAccountManager::getAccountDetails(std::shared_ptr<IAccount> account) {
        return account->getDetails();
    }
} // bank
