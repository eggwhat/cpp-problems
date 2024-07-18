#pragma once

#include <memory>
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
            }
        };

        static std::unique_ptr<sqlite3, Closer> makeSqlite(std::string const& dbName)
        {
            sqlite3* buffer = nullptr;
            int const err = sqlite3_open(dbName.c_str(), &buffer);
            if (err) {
                throw std::runtime_error("failed to open sqlite");
            }
            return std::unique_ptr<sqlite3, Closer>(buffer);
        }
    };
}
