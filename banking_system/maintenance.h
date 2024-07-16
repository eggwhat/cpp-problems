#pragma once

#include <map>
#include <vector>
#include <functional>
#include <utility>

#include "person.h"
#include "interfaces/i_account.h"
#include "interfaces/i_manager.h"

namespace bank {
    class Maintenance {
    public:
        Maintenance();

        void listClients() const;
        void listClientAccounts() const;
        int getClientAccountsCount(unsigned int clientId) const;
        std::multimap<unsigned int, std::unique_ptr<IAccount>>::iterator findClientAccount(unsigned int clientId,
            int accountIndex);
        void addClient(std::shared_ptr<Person> client);
        void addAccount(std::unique_ptr<IAccount> account);
        std::shared_ptr<Person> getClient(unsigned int clientId) const;
        static std::unique_ptr<IManager> createAccountManager(std::unique_ptr<IAccount> const& account);
    private:
        std::vector<std::shared_ptr<Person>> m_clients;
        std::multimap<unsigned int, std::unique_ptr<IAccount>, std::less<>> m_accounts;
    };
}
