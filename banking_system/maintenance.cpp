#include "maintenance.h"

#include <algorithm>
#include <iterator>
#include <iostream>
#include <stdexcept>
#include <utility>

#include "premium_account_manager.h"
#include "standard_account_manager.h"


namespace bank {
    Maintenance::Maintenance() {
        m_clients = std::vector<std::shared_ptr<Person>>();
        m_accounts = std::vector<std::shared_ptr<IAccount>>();
    }

    void Maintenance::listClients() const {
        for(auto const& client: m_clients) {
            std::cout << "Client ID: " << client->id << " " << client->getPersonDetails() << std::endl;
        }
    }

    void Maintenance::listClientAccount(std::vector<std::unique_ptr<IAccount>> const& accounts) {
        for(int i = 0; i < accounts.size(); ++i) {
            std::cout << i << ": " << accounts[i]->getDetails() << std::endl;
        }
    }

    std::vector<std::shared_ptr<IAccount>> Maintenance::findClientAccounts(unsigned int const clientId) {
        std::vector<std::shared_ptr<IAccount>> matches;
        std::copy_if(std::begin(m_accounts), std::end(m_accounts), std::back_inserter(matches),
            [&] (std::shared_ptr<IAccount> const& account){ return clientId == account->getUserId();});
        if(!matches.empty()) {
            return matches;
        }
        throw std::runtime_error("User not found!");
    }

    void Maintenance::createAccount(IManager& manager) {
        manager.createAccount("", "","");
    }

    std::unique_ptr<IManager> Maintenance::createAccountManager(std::shared_ptr<IAccount> const& account) {
        if (account->accountType == IAccount::AccountType::Standard) {
            return std::make_unique<StandardAccountManager>();
        }
        else {
            return std::make_unique<PremiumAccountManager>();
        }
    }
} // bank
