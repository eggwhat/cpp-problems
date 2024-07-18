#pragma once

#include <memory>
#include <sqlite3.h>

#include "interfaces/i_database.h"
#include <utils/sqlite_wrapper.h>

namespace banking {
    class BankingDatabase : public IDatabase {
    public:
        void openDatabase(const std::string& dbName) override;
        int executeQuery(const std::string& query, int (*callback)(void*, int, char**, char**), void* data) override;
        int createTable() override;
        int insertData() override;
        int selectData() override;
    private:
        std::unique_ptr<sqlite3, SqliteWrapper::Closer> m_database;

        static int callback(void* data, int argc, char** argv, char** azColName);
    };
}
