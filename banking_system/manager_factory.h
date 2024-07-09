#pragma once

#include <memory>

#include "i_manager.h"

namespace bank {
    class ManagerFactory {
    public:
        virtual ~ManagerFactory() = default;

        virtual std::unique_ptr<IManager> createManager();
    };
}
