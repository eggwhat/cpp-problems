#pragma once

#include "interfaces/i_json_serializable.h"

namespace banking {
    class JsonSerializer {
    public:
        static bool Serialize(std::shared_ptr<IJsonSerializable> const& obj, std::string& output );
        static bool Deserialize(std::shared_ptr<IJsonSerializable> const& obj, std::string const& input );

    private:
        JsonSerializer() {};
    };
}
