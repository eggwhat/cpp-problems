#pragma once

#include "interfaces/i_json_serializable.h"

namespace banking {
    class JsonSerializer {
    public:
        static bool serialize(IJsonSerializable* pObj, std::string& output );
        static bool deserialize(IJsonSerializable* pObj, std::string const& input );

    private:
        JsonSerializer() {};
    };
}
