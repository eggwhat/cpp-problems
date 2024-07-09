#pragma once

#include "manager_factory.h"

namespace bank {
    class StandardAccountManagerFactory: public ManagerFactory {
    public:
        std::unique_ptr<IManager> createManager() override;
    };
}
