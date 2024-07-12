#include <iostream>


#include "command_line_interface.h"
#include "exceptions/exception.h"

int main() {
    auto maintenance = bank::Maintenance();
    bank_cli::CommandLineInterface cli;
    cli.init(maintenance);
    return 0;
}
