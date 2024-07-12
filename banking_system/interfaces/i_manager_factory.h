#pragma once

#include <memory>

#include "i_manager.h"

namespace bank {
    class IManagerFactory {
    public:
        virtual ~IManagerFactory() = default;

        virtual std::unique_ptr<IManager> createManager() = 0;
    };
}
