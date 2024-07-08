#include "maintance.h"

#include <algorithm>
#include <iterator>
#include <iostream>
#include <stdexcept>


namespace bank {
    Maintance::Maintance() {
        m_clients = std::vector<std::shared_ptr<Person>>();
        m_accounts = std::vector<std::unique_ptr<IAccount>>();
    }

    void Maintance::listClients() const {
        for(auto const& client: m_clients) {
            std::cout << "Client ID: " << client->id << " " << client->getPersonDetails() << std::endl;
        }
    }

    void Maintance::listClientAccount(std::vector<std::unique_ptr<IAccount>> const& accounts) {
        for(int i = 0; i < accounts.size(); ++i) {
            std::cout << i << ": " << accounts[i]->getDetails() << std::endl;
        }
    }

    std::vector<std::unique_ptr<IAccount>> Maintance::findClientAccounts(unsigned int const clientId) {
        std::vector<std::unique_ptr<IAccount>> matches;
        auto it = std::copy_if(std::begin(m_accounts), std::end(m_accounts),
            std::back_inserter(matches), [&] (std::unique_ptr<IAccount> const& account)
            { return clientId == account->getUserId();});
        if(!matches.empty()) {
            return matches;
        }
        throw std::runtime_error("User not found!");
    }

    std::unique_ptr<IManager> Maintance::chooseAccount(std::unique_ptr<IAccount> const& account) {
        return std::move(account->getAccountManager());
    }
} // bank
