#pragma once

#include <json/json.h>

namespace banking {
    class IJsonSerializable {
    public:
        virtual ~IJsonSerializable() = default;
        virtual void Serialize(Json::Value& root ) = 0;
        virtual void Deserialize(Json::Value& root) = 0;
    };
}
