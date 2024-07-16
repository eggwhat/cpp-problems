#include "exception.h"

namespace exceptions {

    Exception::Exception(std::string const &message)  :m_message( "Exception raised! Details: " + message) {}

    char const* Exception::what() const noexcept {
        return m_message.c_str();
    }
}
