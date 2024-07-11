#pragma once

#include <vector>

#include "person.h"
#include "i_account.h"
#include "i_manager.h"

namespace bank {
    class Maintenance {
    private:
        std::vector<std::shared_ptr<Person>> m_clients;
        std::vector<std::shared_ptr<IAccount>> m_accounts;
    public:
        Maintenance();

        void listClients() const;
        static void listClientAccounts(std::vector<std::shared_ptr<IAccount>> const& accounts) ;
        std::vector<std::shared_ptr<IAccount>> findClientAccounts(unsigned int clientId);
        void addClient(std::shared_ptr<Person> client);
        void addAccount(std::shared_ptr<IAccount> account);
        std::shared_ptr<Person> getClient(unsigned int clientId) const;
        static std::unique_ptr<IManager> createAccountManager(std::shared_ptr<IAccount> const& account);
    };
}
