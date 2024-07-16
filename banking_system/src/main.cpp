#include "command_line_interface.h"

int main() {
    auto maintenance = bank::Maintenance();
    auto cli = bank_cli::CommandLineInterface(maintenance);
    cli.init();
    return 0;
}
