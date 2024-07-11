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
            std::cout << "Client ID: " << client->id << ". Details: " << client->getPersonDetails() << std::endl;
        }
    }

    void Maintenance::listClientAccounts(std::vector<std::shared_ptr<IAccount>> const& accounts) {
        for(int i = 0; i < accounts.size(); ++i) {
            std::cout << "Account nr " << i << ". Client: " << accounts[i]->getDetails() << std::endl;
        }
    }

    std::vector<std::shared_ptr<IAccount>> Maintenance::findClientAccounts(unsigned int const clientId) {
        std::vector<std::shared_ptr<IAccount>> matches;
        std::copy_if(std::begin(m_accounts), std::end(m_accounts), std::back_inserter(matches),
            [&] (std::shared_ptr<IAccount> const& account){ return clientId == account->getUserId();});
        return matches;
    }

    void Maintenance::addClient(std::shared_ptr<Person> client) {
        m_clients.push_back(std::move(client));
    }

    void Maintenance::addAccount(std::shared_ptr<IAccount> account) {
        m_accounts.push_back(std::move(account));
    }

    std::shared_ptr<Person> Maintenance::getClient(unsigned int clientId) const {
        auto const it =  std::find_if(m_clients.begin(), m_clients.end(),
            [=](std::shared_ptr<Person> const& client){ return clientId == client->id;});
        if(it != std::end(m_clients))
            return *it;
        return nullptr;
    }

    std::unique_ptr<IManager> Maintenance::createAccountManager(std::shared_ptr<IAccount> const& account) {
        if (account->accountType == IAccount::AccountType::Standard) {
            return std::make_unique<StandardAccountManager>();
        }
        return std::make_unique<PremiumAccountManager>();
    }
} // bank
