#include "standard_account_manager_factory.h"

#include "standard_account_manager.h"

namespace bank {
    std::unique_ptr<IManager> StandardAccountManagerFactory::createManager() {
        return std::make_unique<StandardAccountManager>();
    }

} // bank
