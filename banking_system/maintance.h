#pragma once

#include <vector>

#include "person.h"
#include "i_account.h"

namespace bank {
    class Maintance {
    private:
        std::vector<std::shared_ptr<Person>> m_clients;
        std::vector<std::unique_ptr<IAccount>> m_accounts;
    public:
        Maintance();

        std::unique_ptr<IAccount> maintance(Person const& person);
        void listClients() const;
    };
}