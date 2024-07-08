#include "maintance.h"

namespace bank {
    Maintance::Maintance() {
        m_clients = std::vector<std::shared_ptr<Person>>();
        m_accounts = std::vector<std::unique_ptr<IAccount>>();
    }

    std::unique_ptr<IAccount> Maintance::maintance(Person const &person) {

    }

} // bank