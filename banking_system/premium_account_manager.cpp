#include "premium_account_manager.h"

#include "funds_eur.h"
#include "premium_account.h"

namespace bank {
    std::unique_ptr<IAccount> PremiumAccountManager::createAccount(std::string const& _firstName,
            std::string const& _middleName, std::string const& _lastName) {
        auto person = std::make_unique<Person>(Person(_firstName, _middleName, _lastName));
        std::shared_ptr<IFunds> funds = std::shared_ptr<FundsEUR>(new FundsEUR(23.0));
        return std::make_unique<IAccount>(PremiumAccount(person, funds));
    }

    void PremiumAccountManager::depositMoney() {

    }

    void PremiumAccountManager::withdrawMoney() {

    }

    std::string PremiumAccountManager::getAccountDetails() {
        return "";
    }
} // bank
