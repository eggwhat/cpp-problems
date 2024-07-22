#pragma once

#include <string>
#include <vector>

#include "banking/person.h"

namespace banking {
    class IDatabase {
    public:
        virtual ~IDatabase() = default;

        virtual void openDatabase(const std::string& dbName) = 0;
        virtual int executeQuery(const std::string& query, int (*callback)(void*, int, char**, char**), void* data) = 0;
        virtual int createTable() = 0;
        virtual int insertData(std::string const& token, std::string const& jsonDetails) = 0;
        virtual int selectData() = 0;
        virtual int getClient(unsigned int clientId, std::unique_ptr<std::unique_ptr<bank::Person>> const& client) = 0;
    };
}
