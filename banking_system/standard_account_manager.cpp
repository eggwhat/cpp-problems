#include "standard_account_manager.h"

#include "funds_eur.h"
#include "standard_account.h"

namespace bank {

    std::unique_ptr<IAccount> StandardAccountManager::createAccount(std::shared_ptr<Person> person, std::unique_ptr<IFunds> funds) {
        return std::make_unique<StandardAccount>(std::move(person), std::move(funds));
    }

    void StandardAccountManager::depositMoney(std::shared_ptr<IAccount> account, double const money) {
        account->depositMoney(money);
    }

    void StandardAccountManager::withdrawMoney(std::shared_ptr<IAccount> account, double const money) {
        account->withdrawMoney(money);
    }

    std::string StandardAccountManager::getAccountDetails(std::shared_ptr<IAccount> account) {
        return account->getDetails();
    }
} // bank
