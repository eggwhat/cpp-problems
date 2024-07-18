#include <algorithm>
#include <iterator>
#include <iostream>
#include <stdexcept>

#include <banking/maintenance.h>
#include <boost/range/algorithm.hpp>

#include <banking/account.h>
#include <banking/premium_account_manager.h>
#include <banking/standard_account_manager.h>
#include <exceptions/client_not_found.h>
#include <exceptions/no_accounts_found_for_given_client_id.h>
#include <exceptions/no_clients_present.h>


namespace bank {
    Maintenance::Maintenance() : m_clients(std::vector<std::shared_ptr<Person>>()) {}

    void Maintenance::listClients() const {
        if (m_clients.empty()) {
            throw exceptions::NoClientsPresent();
        }

        for(auto const& client: m_clients) {
            std::cout << "Client ID: " << client->id << ". Details: " << client->getPersonDetails() << std::endl;
        }
    }

    void Maintenance::listClientAccounts() const {
        int index = 0;
        for(auto const& account: m_accounts) {
            std::cout << "Account nr " << index << ". Client: " << account.second->getDetails() << std::endl;
            ++index;
        }
    }

    void Maintenance::listStatistics() const {
        auto const numberOfPremiumAccounts = boost::range::count_if(m_accounts,
            [](std::pair<unsigned int const, std::unique_ptr<IAccount> const&> const& account)
            { return account.second->isPremium(); });
        std::cout << "Accounts statistics: " << std::endl
            << "total: " << m_accounts.size() << std::endl
            << "standard: " << m_accounts.size() - numberOfPremiumAccounts << std::endl
            << "premium: " << numberOfPremiumAccounts << std::endl;
    }

    int Maintenance::getClientAccountsCount(unsigned int const clientId) const {
        int accountsCount = m_accounts.count(clientId);
        if (0 == accountsCount) {
            throw exceptions::NoAccountFoundForGivenClientId();
        }
        return accountsCount;
    }

    std::shared_ptr<Person> Maintenance::getClient(unsigned int clientId) const {
        auto const it =  std::find_if(m_clients.begin(), m_clients.end(),
            [=](std::shared_ptr<Person> const& client){ return clientId == client->id;});
        if(it == std::end(m_clients)) {
            throw exceptions::ClientNotFound();
        }

        return *it;
    }

    std::multimap<unsigned int, std::unique_ptr<IAccount>>::iterator Maintenance::findClientAccount(
        unsigned int const clientId, int const accountIndex) {
        auto it = m_accounts.find(clientId);
        for(int i = 0; i < accountIndex; ++i, ++it) {}
        if (it == m_accounts.end()) {
            throw exceptions::NoAccountFoundForGivenClientId();
        }
        return it;
    }

    void Maintenance::addClient(std::shared_ptr<Person> client) {
        m_clients.push_back(std::move(client));
    }

    void Maintenance::addAccount(std::unique_ptr<IAccount> account) {
        m_accounts.emplace(account->getUserId(), std::move(account));
    }

    std::unique_ptr<IManager> Maintenance::createAccountManager(std::unique_ptr<IAccount> const& account) {
        if (account->isPremium()) {
            return std::make_unique<PremiumAccountManager>();
        }
        return std::make_unique<StandardAccountManager>();
    }
} // bank
