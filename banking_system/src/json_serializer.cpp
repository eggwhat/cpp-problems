#include "utils/json_serializer.h"

namespace banking {

    bool JsonSerializer::serialize(std::shared_ptr<IJsonSerializable> const& obj, std::string& output )
    {
        Json::Value serializeRoot;
        obj->serialize(serializeRoot);

        Json::StyledWriter writer;
        output = writer.write( serializeRoot );

        return true;
    }

    bool JsonSerializer::deserialize(std::shared_ptr<IJsonSerializable> const& obj, std::string const& input )
    {
        Json::Value deserializeRoot;
        Json::Reader reader;

        if (!reader.parse(input, deserializeRoot) )
            return false;

        obj->deserialize(deserializeRoot);

        return true;
    }
}