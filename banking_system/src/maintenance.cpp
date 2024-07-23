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

#include "banking/banking_database.h"
#include "utils/json_serializer.h"


namespace bank {
    Maintenance::Maintenance() {
        m_database = std::make_unique<banking::BankingDatabase>();
        m_database->openDatabase("file:../../bank.db");
        m_database->createTable();
    }

    void Maintenance::listClients() const {
        m_database->selectData();
    }

    void Maintenance::listClientAccounts(std::unique_ptr<Person> const& client) const {
        int index = 0;
        for(auto const& account: m_accounts) {
            std::cout << "Account nr " << index << ". Client: " << client->getPersonDetails() << " " <<
                account.second->getDetails() << std::endl;
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

    void Maintenance::getClient(unsigned int const clientId, std::unique_ptr<std::unique_ptr<Person>> const& client) const {
        m_database->getClient(clientId, client);
        if(*client == nullptr) {
            throw exceptions::ClientNotFound();
        }
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

    void Maintenance::addClient(std::unique_ptr<Person> const& client) {
        std::string serializedClient;
        banking::JsonSerializer::serialize(client.get(), serializedClient);
        m_database->insertData(client->getPersonDetails(), serializedClient);
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
