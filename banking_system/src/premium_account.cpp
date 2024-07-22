#include <banking/premium_account.h>

#include <banking/premium_account_manager.h>


namespace bank {

    PremiumAccount::PremiumAccount(unsigned int const clientId, std::unique_ptr<IFunds> funds):
            Account(clientId, std::move(funds), AccountType::Premium) {
        benefits = std::set<Benefits> { Benefits::FreeChecks, Benefits::DedicatedCustomerService };
    }

    std::string PremiumAccount::getDetails() {
        return "Type: premium \n" + m_funds->getDetails() + "Benefits: " + std::to_string(benefits.size()) + '\n';
    }
} // bank
