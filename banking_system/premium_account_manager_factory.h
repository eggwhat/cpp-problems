#pragma once

#include "interfaces/i_manager_factory.h"

namespace bank {
    class PremiumAccountManagerFactory: public IManagerFactory {
    public:
        std::unique_ptr<IManager> createManager() override;
    };
}
