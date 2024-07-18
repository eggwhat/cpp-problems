#pragma once

#include <string>

namespace banking {
    class IDatabase {
    public:
        virtual ~IDatabase() = default;

        virtual void openDatabase(const std::string& dbName) = 0;
        virtual int executeQuery(const std::string& query, int (*callback)(void*, int, char**, char**), void* data) = 0;
        virtual int createTable() = 0;
        virtual int insertData() = 0;
        virtual int selectData() = 0;
    };
}
