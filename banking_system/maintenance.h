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
        static void listClientAccounts(std::vector<std::vector<std::unique_ptr<IAccount>>::iterator> const& accounts) ;
        std::vector<std::vector<std::unique_ptr<IAccount>>::iterator> findClientAccounts(unsigned int clientId);
        void addClient(std::shared_ptr<Person> client);
        void addAccount(std::unique_ptr<IAccount> account);
        std::shared_ptr<Person> getClient(unsigned int clientId) const;
        static std::unique_ptr<IManager> createAccountManager(std::unique_ptr<IAccount> const& account);
    };
}
