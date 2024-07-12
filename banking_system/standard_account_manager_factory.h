#pragma once

#include "interfaces/i_manager_factory.h"

namespace bank {
    class StandardAccountManagerFactory: public IManagerFactory {
    public:
        std::unique_ptr<IManager> createManager() override;
    };
}
