#pragma once

#include <json/json.h>

namespace banking {
    class IJsonSerializable {
    public:
        virtual ~IJsonSerializable() = default;
        virtual void serialize(Json::Value& root ) = 0;
        virtual void deserialize(Json::Value& root) = 0;
    };
}
