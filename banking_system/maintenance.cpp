#include "maintenance.h"

#include <algorithm>
#include <iterator>
#include <iostream>
#include <stdexcept>
#include <utility>

#include "account.h"
#include "premium_account_manager.h"
#include "standard_account_manager.h"
#include "exceptions/client_not_found.h"
#include "exceptions/no_accounts_found_for_given_client_id.h"
#include "exceptions/no_clients_present.h"


namespace bank {
    Maintenance::Maintenance() : m_clients(std::vector<std::shared_ptr<Person>>()),
        m_accounts(std::vector<std::unique_ptr<IAccount>>()) {}

    void Maintenance::listClients() const {
        if (m_clients.empty()) {
            throw exceptions::NoClientsPresent();
        }

        for(auto const& client: m_clients) {
            std::cout << "Client ID: " << client->id << ". Details: " << client->getPersonDetails() << std::endl;
        }
    }

    void Maintenance::listClientAccounts(std::vector<std::vector<std::unique_ptr<IAccount>>::iterator> const& accounts) {
        for(int i = 0; i < accounts.size(); ++i) {
            std::cout << "Account nr " << i << ". Client: " << (*accounts[i])->getDetails() << std::endl;
        }
    }

    std::vector<std::vector<std::unique_ptr<IAccount>>::iterator> Maintenance::findClientAccounts(unsigned int const clientId) {
        auto isClientAccount = [&clientId] (std::unique_ptr<IAccount> const& account)
            { return clientId == account->getUserId();};
        std::vector<std::vector<std::unique_ptr<IAccount>>::iterator> matches;
        for ( auto it = std::find_if(m_accounts.begin(), m_accounts.end(), isClientAccount);
            it != m_accounts.end(); it = std::find_if(++it, m_accounts.end(), isClientAccount)) {
            matches.push_back(it);
        }
        if (matches.empty()) {
            throw exceptions::NoAccountFoundForGivenClientId();
        }

        return matches;
    }

    void Maintenance::addClient(std::shared_ptr<Person> client) {
        m_clients.push_back(std::move(client));
    }

    void Maintenance::addAccount(std::unique_ptr<IAccount> account) {
        m_accounts.push_back(std::move(account));
    }

    std::shared_ptr<Person> Maintenance::getClient(unsigned int clientId) const {
        auto const it =  std::find_if(m_clients.begin(), m_clients.end(),
            [=](std::shared_ptr<Person> const& client){ return clientId == client->id;});
        if(it == std::end(m_clients)) {
            throw exceptions::ClientNotFound();
        }

        return *it;
    }

    std::unique_ptr<IManager> Maintenance::createAccountManager(std::unique_ptr<IAccount> const& account) {
        if (account->isPremium()) {
            return std::make_unique<PremiumAccountManager>();
        }
        return std::make_unique<StandardAccountManager>();
    }
} // bank
