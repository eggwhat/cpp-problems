#include "utils/json_serializer.h"

namespace banking {

    bool JsonSerializer::serialize(IJsonSerializable* const pObj, std::string& output )
    {
        Json::Value serializeRoot;
        pObj->serialize(serializeRoot);

        Json::StyledWriter writer;
        output = writer.write( serializeRoot );

        return true;
    }

    bool JsonSerializer::deserialize(IJsonSerializable* const pObj, std::string const& input )
    {
        Json::Value deserializeRoot;
        Json::Reader reader;

        if (!reader.parse(input, deserializeRoot) )
            return false;

        pObj->deserialize(deserializeRoot);

        return true;
    }
}
