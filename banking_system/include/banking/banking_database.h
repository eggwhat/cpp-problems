#pragma once

#include <memory>
#include <string>
#include <shared_mutex>
#include <sqlite3.h>

#include "interfaces/i_database.h"
#include <utils/sqlite_wrapper.h>

namespace banking {
    class BankingDatabase : public IDatabase {
    public:
        BankingDatabase() = default;

        void openDatabase(const std::string& dbName) override;
        int executeQuery(const std::string& query, int (*callback)(void*, int, char**, char**), void* data) override;
        int createTable() override;
        int insertData(std::string const& token, std::string const& jsonDetails) override;
        int selectData() override;
        int getClient(unsigned int clientId, std::unique_ptr<std::unique_ptr<bank::Person>> const& client) override;
    private:
        std::unique_ptr<sqlite3, SqliteWrapper::Closer> m_database;

        static int printCallback(void* data, int argc, char** argv, char** azColName);
        static int getCallback(void* data, int argc, char** argv, char** azColName);

        std::shared_timed_mutex m_mutex;
    };
}
