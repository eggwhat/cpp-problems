#pragma once

#include <map>
#include <vector>
#include <functional>
#include <sqlite3.h>
#include <utility>

#include "person.h"
#include "interfaces/i_account.h"
#include "interfaces/i_manager.h"
#include <utils/sqlite_wrapper.h>

#include "interfaces/i_database.h"

namespace bank {
    class Maintenance {
    public:
        Maintenance();

        void listClients() const;
        void listClientAccounts(std::unique_ptr<Person> const& client) const;
        void listStatistics() const;
        int getClientAccountsCount(unsigned int clientId) const;
        void getClient(unsigned int clientId, std::unique_ptr<std::unique_ptr<Person>> const& client) const;

        std::multimap<unsigned int, std::unique_ptr<IAccount>>::iterator findClientAccount(unsigned int clientId,
            int accountIndex);
        void addClient(std::unique_ptr<Person> const& client);
        void addAccount(std::unique_ptr<IAccount> account);
        static std::unique_ptr<IManager> createAccountManager(std::unique_ptr<IAccount> const& account);
    private:
        std::unique_ptr<banking::IDatabase> m_database;
        std::multimap<unsigned int, std::unique_ptr<IAccount>, std::less<>> m_accounts;
    };
}
