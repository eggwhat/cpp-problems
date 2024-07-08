#include "premium_account_manager.h"

#include "funds_eur.h"
#include "premium_account.h"

namespace bank {
    std::unique_ptr<IAccount> PremiumAccountManager::createAccount(std::string const& firstName,
            std::string const& middleName, std::string const& lastName) {
        auto person = std::make_shared<Person>(Person(firstName, middleName, lastName));
        std::unique_ptr<IFunds> funds = std::make_unique<FundsEUR>(0.0);
        return std::make_unique<PremiumAccount>(std::move(person), std::move(funds));
    }

    void PremiumAccountManager::depositMoney(std::unique_ptr<IAccount> account) {

    }

    void PremiumAccountManager::withdrawMoney(std::unique_ptr<IAccount> account) {

    }

    std::string PremiumAccountManager::getAccountDetails(std::unique_ptr<IAccount> account) {
        return account->getDetails();
    }
} // bank
