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

namespace bank {
    class Maintenance {
    public:
        Maintenance();

        void listClients() const;
        void listClientAccounts() const;
        void listStatistics() const;
        int getClientAccountsCount(unsigned int clientId) const;
        std::shared_ptr<Person> getClient(unsigned int clientId) const;

        std::multimap<unsigned int, std::unique_ptr<IAccount>>::iterator findClientAccount(unsigned int clientId,
            int accountIndex);
        void addClient(std::shared_ptr<Person> client);
        void addAccount(std::unique_ptr<IAccount> account);
        static std::unique_ptr<IManager> createAccountManager(std::unique_ptr<IAccount> const& account);
    private:
        std::unique_ptr<sqlite3, banking::SqliteWrapper::Closer> m_database;
        std::multimap<unsigned int, std::unique_ptr<IAccount>, std::less<>> m_accounts;
    };
}
