#pragma once

#include <vector>

#include "person.h"
#include "i_account.h"
#include "i_manager.h"

namespace bank {
    class Maintenance {
    private:
        std::vector<std::shared_ptr<Person>> m_clients;
        std::vector<std::unique_ptr<IAccount>> m_accounts;
    public:
        Maintenance();

        void listClients() const;
        static void listClientAccount(std::vector<std::unique_ptr<IAccount>> const& accounts) ;
        std::vector<std::unique_ptr<IAccount>> findClientAccounts(unsigned int clientId);
        static std::unique_ptr<IManager> chooseAccount(std::unique_ptr<IAccount> const& account);
    };
}
