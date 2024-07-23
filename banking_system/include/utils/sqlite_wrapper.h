#pragma once

#include <memory>
#include <iostream>
#include <stdexcept>
#include <sqlite3.h>
#include <string>

namespace banking {
    struct SqliteWrapper {
        struct Closer
        {
            void operator()(sqlite3* p) const
            {
                sqlite3_close(p);
                std::cout << "Database closed!" << std::endl;
            }
        };

        static std::unique_ptr<sqlite3, Closer> makeSqlite(std::string const& dbName)
        {
            sqlite3* buffer = nullptr;
            int const err = sqlite3_open_v2(dbName.c_str(), &buffer, SQLITE_OPEN_READWRITE | SQLITE_OPEN_URI,
                nullptr);
            if (err) {
                throw std::runtime_error("failed to open sqlite");
            }
            std::cout << "Database opened!" << std::endl;
            return std::unique_ptr<sqlite3, Closer>(buffer);
        }
    };
}
