#include <banking/banking_database.h>

#include <iostream>
#include <boost/format.hpp>

namespace banking {

    void BankingDatabase::openDatabase(const std::string &dbName) {
        m_database = SqliteWrapper::makeSqlite(dbName);
    }

    int BankingDatabase::executeQuery(const std::string &query, int(*callback)(void *, int, char **, char **),
        void *data) {
        char* errMsg = nullptr;
        return sqlite3_exec(m_database.get(), query.c_str(), callback, data, &errMsg);
    }

    int BankingDatabase::createTable() {
        std::string const query = "CREATE TABLE IF NOT EXISTS Clients(Id INTEGER PRIMARY KEY, Token varchar(50), Details TEXT);";
        return executeQuery(query, nullptr, nullptr);
    }

    int BankingDatabase::insertData(std::string const& token, std::string const& jsonDetails) {
        auto query = boost::format("INSERT INTO MyTable(Token, Details) VALUES('%1%', '%2%');")
        % token % jsonDetails;
        return executeQuery(query.str(), nullptr, nullptr);
    }

    int BankingDatabase::selectData() {
        std::string const query = "SELECT * FROM Clients;";
        return executeQuery(query, callback, nullptr);
    }

    int BankingDatabase::callback(void* data, int argc, char** argv, char** azColName) {
        for (int i = 0; i < argc; ++i) {
            std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << '\n';
        }
        std::cout << '\n';
        return 0;
    }
}
