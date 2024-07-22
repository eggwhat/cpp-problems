#include <banking/banking_database.h>

#include <iostream>
#include <cstdlib>
#include <boost/format.hpp>

#include "banking/person.h"
#include "utils/json_serializer.h"

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
        std::string const query = "CREATE TABLE IF NOT EXISTS Clients(Id INTEGER PRIMARY KEY, Token varchar(255), Details TEXT);";
        return executeQuery(query, nullptr, nullptr);
    }

    int BankingDatabase::insertData(std::string const& token, std::string const& jsonDetails) {
        auto const query = boost::format("INSERT INTO Clients(Token, Details) VALUES('%1%', '%2%');")
            % token % jsonDetails;
        return executeQuery(query.str(), nullptr, nullptr);
    }

    int BankingDatabase::selectData() {
        std::string const query = "SELECT * FROM Clients;";
        return executeQuery(query, printCallback, nullptr);
    }

    int BankingDatabase::getClient(unsigned int const clientId, std::vector<std::unique_ptr<bank::Person>>* clients) {
        // TODO: fix security issue
        auto const query = boost::format("SELECT * FROM Clients WHERE Id = %1%;") % clientId;

        return executeQuery(query.str(), getCallback, clients);
    }

    int BankingDatabase::printCallback(void* data, int argc, char** argv, char** azColName) {
        for (int i = 0; i < argc; ++i) {
            std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << '\n';
        }
        std::cout << '\n';
        return 0;
    }

    int BankingDatabase::getCallback(void* data, int argc, char** argv, char** azColName) {
        auto* results = static_cast<std::vector<std::unique_ptr<bank::Person>> *>(data);
        auto client = std::make_unique<bank::Person>("", argv[2], argv[1], std::atoi(argv[0]));
        JsonSerializer::deserialize(client.get(), argv[2]);
        results->emplace_back(std::move(client));
        return 0;
    }
}
