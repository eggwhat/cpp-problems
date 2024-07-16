#include "premium_account_manager_factory.h"

#include "premium_account_manager.h"

namespace bank {
    std::unique_ptr<IManager> PremiumAccountManagerFactory::createManager() {
        return std::make_unique<PremiumAccountManager>();
    }
} // bank
