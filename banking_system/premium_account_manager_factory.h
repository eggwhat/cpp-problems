#pragma once

#include "manager_factory.h"

namespace bank {
    class PremiumAccountManagerFactory: public ManagerFactory {
    public:
        std::unique_ptr<IManager> createManager() override;
    };
}
