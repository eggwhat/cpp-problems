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
        for(unsigned int i = 0; i < m_clients.size(); ++i) {
            std::cout << i << ": " << m_clients[i]->getPersonDetails() << std::endl;
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
} // bank
