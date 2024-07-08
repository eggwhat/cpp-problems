#include "maintance.h"

#include <algorithm>
#include <iterator>
#include <iostream>

namespace bank {
    Maintance::Maintance() {
        m_clients = std::vector<std::shared_ptr<Person>>();
        m_accounts = std::vector<std::unique_ptr<IAccount>>();
    }

    std::unique_ptr<IAccount> Maintance::maintance(Person const& person) {
        auto it = std::find_if(std::begin(m_accounts), std::end(m_accounts),
            [&] (std::unique_ptr<IAccount> const& account) { return person.id == account->getUserId();});
        if(it != std::end(m_accounts)) {
            return std::move(*it);
        }
        std::cout << "User not found" << std::endl;
        return nullptr;
    }

    void Maintance::listClients() const {
        for(unsigned int i = 0; i < m_clients.size(); ++i) {
            std::cout << i << ": " << m_clients[i]->getPersonDetails() << std::endl;
        }
    }
} // bank